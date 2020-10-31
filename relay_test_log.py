import RPi.GPIO as GPIO
import requests
import json
import time
from datetime import timezone, timedelta
import datetime as dt
import pandas as pd
import urllib.request
import urllib.parse

GPIO.setmode(GPIO.BCM)

global pinlist
pinlist=[24,23]
#for i in pinlist:
#    GPIO.setup(i, GPIO.OUT)
#    GPIO.output(i, GPIO.LOW)

natu='http://192.168.1.241:8200/last/600261'
top_h='http://192.168.1.241:8200/last/500664'
top_a='http://192.168.1.241:8200/last/50065A'
toplight=[top_h,top_a]

global lightsum
global nat_compare

global on_off_lim # laika limits cik lampām jābūt ieslēgr\tām/izslēgtām

global half_light_status_on
global half_off_tresh # Izslēgšanās limits
global half_off_counter # izslēgšanās laika skaitītājs
global half_on_tresh # atkārtotas ieslēgšanās limits
global half_on_counter
global half_lightsum_lim
global half_GPIO

global all_light_status_on
global all_off_tresh # Izslēgšanās limits
global all_off_counter # izslēgšanās laika skaitītājs
global all_on_tresh # atkārtotas ieslēgšanās limits
global all_on_counter
global all_lightsum_lim
global all_GPIO

half_lightsum_lim=28 # Gaismas summas limits, pie kuras atslēgsies gaisma
half_off_tresh=500 # Izslēgšanās limits
half_on_tresh=350 # atpakaļieslēgšanās limits

all_lightsum_lim=26 #
all_off_tresh=300 # Izslēgšanās limits
all_on_tresh=180

half_light_status_on=True # Mākslīgo gaismu -lampu ielēgšanās status
half_GPIO=0
all_light_status_on=True # Mākslīgo gaismu -lampu ielēgšanās status
all_GPIO=0

nat_compare=0
lightsum=12 #  kopējā gaismas summa
art_umol=0.0102 # Akumulētā gaismas summa pie 60sek darbības, jo uzstādīti 170
natk=60 # sekundes minūtē
on_off_lim=15 # minūtes, cik ilgi gaismai jāatdziest un jāuzsilst

half_off_counter=15 # izslēgšanās laika skaitītājs līdz brīdim lai būtu izslēgtas
half_on_counter=0

all_off_counter=15 # izslēgšanās laika skaitītājs līdz brīdim lai būtu izslēgtas
all_on_counter=0

# Ieavadm - kad sākam gaismot un kad beidzam
global start_hour
global start_minute
global end_hour
global end_minute
global all_start_delay
global all_end_delay
global half_on_start_time
global half_off_end_time
global all_on_start_time
global all_off_end_time

start_hour=22 # Stunda cikos sākam gaismot -
start_minute=00 # Minūte cikos sākam gaismot
end_hour=16 #Stunda, ckios beidzam gaismot
end_minute=59  #Minūte, kurā beidzam stundas robežās gaismot
all_start_delay=30 # 100% ieslēgšanās aizture
all_end_delay=15 # 100% izslēgšanās pirms visu lampu izslēgšanās

# Šos neaiztiekam - tie ir laika logi
half_on_start_time=0
half_off_end_time=0
all_on_start_time=0
all_off_end_time=0

notachii=0
global finame
finame=0

#Nodefinējam laika funkciju gaismu ieslēgšanai:
def daily_artifical_range_half():
    global half_on_start_time
    global half_off_end_time
    half_on_start_time=pd.to_datetime(dt.time(start_hour,start_minute, 0).isoformat())
    half_off_end_time = pd.to_datetime(dt.time(end_hour, end_minute, 0).isoformat())
    if half_on_start_time>half_off_end_time:
        half_off_end_time=half_off_end_time + timedelta(days=1)


def daily_artifical_range_full_start():
    global half_on_start_time
    global all_on_start_time
    if all_start_delay>0:
        all_on_start_time=half_on_start_time + timedelta(minutes=all_start_delay)
    else:
        all_on_start_time=half_on_start_time

def daily_artifical_range_full_end():
    global half_off_end_time
    global all_off_end_time
    if all_end_delay>0:
        all_off_end_time=half_off_end_time - timedelta(minutes=all_end_delay)
    else:
        all_off_end_time=half_off_end_time

def pinflip():
    global pinlist
    global half_GPIO
    global all_GPIO
    pinlist.reverse()
    GPIO.cleanup()
    GPIO.setmode(GPIO.BCM)
    half_GPIO=pinlist[0]
    all_GPIO=pinlist[1]
    GPIO.setup(half_GPIO, GPIO.OUT)
    GPIO.setup(all_GPIO, GPIO.OUT)


def counter_reset():
    global lightsum
    global finame
    now=dt.datetime.now().time().isoformat()
    if int(now[0:2])==start_hour and int(now[3:5])==start_minute:
        lightsum=0
        #timerange_light_on()
        daily_artifical_range_half()
        daily_artifical_range_full_start()
        daily_artifical_range_full_end()
        pinflip()
    date=dt.datetime.now().isoformat()
    finame="/home/juska/log/"+date[5:10]+"_n.txt"

def startup():
    global notachii
    global finame
    global half_on_start_time
    global half_off_end_time
    now=dt.datetime.now().time().isoformat()
    if notachii==0:
        notachii+=1
        if start_hour > int(now[0:2]):
            daily_artifical_range_half()
            """
            Pēc sistēmas restarta, ja restarta periods iekrīt aktīvajā gaismošanas periodā, sistēma uzstāda gaismas ieslēgšanas laiku kā nākamo atbilstošo ieslēgšanās periodu  - tātad nākamajā dienā.
            Lai to novērstu, ar timedelta pārbīdam jau aktivizēto ieslēgšanas un izslēgšanas periodu par diennakti atpakaļ, un attiecīgi esam nepieciešamajā laika periodā un gaisma ieslēgsies.
            """
            half_on_start_time=half_on_start_time - timedelta(days=1)
            half_off_end_time = half_off_end_time - timedelta(days=1)
            daily_artifical_range_full_start()
            daily_artifical_range_full_end()
            pinflip()
        else:
            daily_artifical_range_half()
            daily_artifical_range_full_start()
            daily_artifical_range_full_end()
            pinflip()
    date=dt.datetime.now().isoformat()
    finame="/home/juska/log/"+date[5:10]+"_n.txt"

def get_data(url):
    resp=requests.get(url)
    data=resp.json()
    num=data[0]['v']
    return num

def cumlightsum():
    global lightsum
    global nat_compare
    for url in toplight:
        num=get_data(url)
        if num>1:
            lightsum+=art_umol
        else:
            continue
    nat_level=get_data(natu)
    lightsum+=nat_level*natk
    nat_compare=nat_level*1000000

def half_on_off_status():
    global half_light_status_on
    global half_off_tresh # Izslēgšanās limits
    global half_off_counter # izslēgšanās laika skaitītājs
    global half_on_tresh # atkārtotas ieslēgšanās limits
    global half_on_counter
    global half_lightsum_lim
    if lightsum>half_lightsum_lim and half_light_status_on==True:
        if half_on_counter>on_off_lim:
            half_light_status_on=False
            half_off_counter+=1
            half_on_counter=0
        else:
            half_on_counter+=1
            half_off_counter=0
    elif nat_compare>half_off_tresh and half_light_status_on==True:
        if half_on_counter>on_off_lim:
            half_light_status_on=False
            half_off_counter+=1
            half_on_counter=0
        else:
            half_on_counter+=1
            half_off_counter=0
    elif nat_compare<half_on_tresh and half_light_status_on==False and lightsum<half_lightsum_lim:
        if half_off_counter>on_off_lim:
            half_light_status_on=True
            half_on_counter+=1
            half_off_counter=0
        else:
            half_on_counter+=1
            half_off_counter=0
    elif half_light_status_on==False:
        half_on_counter=0
        half_off_counter+=1
    else:
        half_on_counter+=1
        half_off_counter=0

def all_on_off_status():
    global all_light_status_on
    global all_off_tresh # Izslēgšanās limits
    global all_off_counter # izslēgšanās laika skaitītājs
    global all_on_tresh # atkārtotas ieslēgšanās limits
    global all_on_counter
    global all_lightsum_lim
    if lightsum>all_lightsum_lim and all_light_status_on==True:
        if all_on_counter>on_off_lim:
            all_light_status_on=False
            all_off_counter+=1
            all_on_counter=0
        else:
            all_on_counter+=1
            all_off_counter=0
    elif nat_compare>all_off_tresh and all_light_status_on==True:
        if all_on_counter>on_off_lim:
            all_light_status_on=False
            all_off_counter+=1
            all_on_counter=0
        else:
            all_on_counter+=1
            all_off_counter=0
    elif nat_compare<all_on_tresh and all_light_status_on==False and lightsum<all_lightsum_lim:
        if all_off_counter>on_off_lim:
            all_light_status_on=True
            all_on_counter+=1
            all_off_counter=0
        else:
            all_on_counter+=1
            all_off_counter=0
    elif all_light_status_on==False:
        all_on_counter=0
        all_off_counter+=1
    else:
        all_on_counter+=1
        all_off_counter=0

# daily_artifical_range_half()
# daily_artifical_range_full_start()
# daily_artifical_range_full_end()

def is_in_range(start,end):
    now=pd.to_datetime(dt.datetime.now().isoformat())
    return start<=now<=end


def half_status():
    global half_light_status_on
    global half_off_counter
    global half_on_counter
    if is_in_range(half_on_start_time,half_off_end_time):
        half_on_off_status()

    else:
        half_light_status_on=False
        half_off_counter+=1
        half_on_counter=0



def all_status():
    global all_light_status_on
    global all_off_counter
    global all_on_counter
    if is_in_range(all_on_start_time,all_off_end_time):
        all_on_off_status()
    else:
        all_light_status_on=False
        all_off_counter+=1
        all_on_counter=0

def GPIO_setmode_half():
    global half_light_status_on
    global half_GPIO
    if half_light_status_on:
        GPIO.output(half_GPIO, GPIO.HIGH)
    else:
        GPIO.output(half_GPIO, GPIO.LOW)

def GPIO_setmode_all():
    global all_light_status_on
    global all_GPIO
    if all_light_status_on:
        GPIO.output(all_GPIO, GPIO.HIGH)
    else:
        GPIO.output(all_GPIO, GPIO.LOW)

# Papildinam ar text2reach sms moduli ar paziņojumu par kļūdu
def sendSMS(apikey, numbers, sender, message):
    params = {
        'api_key': apikey,
        'from':sender,
        'phone': numbers,
        'message' : message,
        'type': 'txt',
        'unicode': True,
        # 'timestamp':0,
        # 'report_url':'http://www.yoursite.com/sms/report/handler/',
        # 'expires':0,
        # 'schedule':0,
        # 'blacklist':False
        }
    f = urllib.request.urlopen('https://api.text2reach.com/sms/send?'
        + urllib.parse.urlencode(params))
    return (f.read(), f.code)

def write_log():
    global lightsum
    global nat_compare

    global half_light_status_on
    global half_off_tresh # Izslēgšanās limits
    global half_off_counter # izslēgšanās laika skaitītājs
    global half_on_tresh # atkārtotas ieslēgšanās limits
    global half_on_counter
    global half_GPIO

    global all_light_status_on
    global all_off_tresh # Izslēgšanās limits
    global all_off_counter # izslēgšanās laika skaitītājs
    global all_on_tresh # atkārtotas ieslēgšanās limits
    global all_on_counter
    global all_lightsum_lim
    global all_GPIO
    laiks=dt.datetime.now().isoformat()
    inwrite=laiks +','+str(lightsum) + ','+ str(nat_compare)+','+ str(half_light_status_on)+','+ str(half_off_tresh)+','+ str(half_off_counter)+','+ str(half_on_tresh)+','+ str(half_on_counter)+','+ str(half_GPIO)+','+ str(all_light_status_on)+','+ str(all_off_tresh)+','+ str(all_on_counter)+','+ str(all_GPIO)
    with open(finame, 'a') as f:
        f.writelines("%s\n" % inwrite)


try:
    while True:
        startup()
        counter_reset()
        cumlightsum()
        half_status()
        all_status()
        GPIO_setmode_half()
        GPIO_setmode_all()
        write_log()
        time.sleep(60)
except (KeyboardInterrupt, SystemExit):
    GPIO.cleanup()
    api_key= "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" # 32 zīmju api key
    phonelist=00000000000 # telefona numurs ar valsts kodu bez 00 un +
    sender='random_name' # reģistrētais sūtītāja vārds
    message='lights down'
    sendSMS(api_key,phonelist,sender,message)
    print("Keyboard interrupt exception caught")
