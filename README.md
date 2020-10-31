# RTR-105
Datormācība (pamatkurss) elektroniskā klade

#**ls** 
ls - visi faili un drektorijas . direktorijā
ls -l - parāda failu un direktoriju sarakstu ar to tiesībām, piederību un izmēru baitos
ls -lh - parāda līdzīgi kā -l, bet ar izmēru K, M vai G baitu paplašinājumu
ls Desktop/ - parāda /Desktop adrešu sarakstu
ls -a - parāda pilnu failu un direktoriju sarakstu
ls -a -l - parāda pilnu failu un direktoriju sarakstu, ieskaitot slēptos failus un direktorijas ar tiesībām un izmēru baitos
ls -lt - parāda failu un direktoriju sarakstu ar to tiesībām, piederību un izmēru baitos, šķirojot pēc datuma dilstoši
ls -lrt - tas pats kas lt, tikai augoši, īpaši ērti, ja pievienojam kādu failu, ko gribam izpildīt - tas pēc attainojuma būs blakus aktīvajam kursoram, t.i. sraksta apakšā

#**cd**
cd .. - atpakaļ
cd ~ (tilde) - pārvieto uz mājas direktoriju
cd home/user - pārvieto uz mājas diektorijas adresi
cd / - pārvieto uz root adresi

#** Darbības ar failiem un direktorijām**
**mkdir** - izveidot direktoriju, saīsinājums no make directory
**rmdir** - izdžest direktoriju, saīsinājums no remove directory
**touch** - rada tukšu failu
**touch sample.txt** - rada failu ar nosaukumu sample un faila paplašinājumu .txt direktorijā, kurā atrodamies
**touch /home/user/rubbish/garbage.txt** - izveido garbage.txt failu direktorijā /home/user/rubbish/
-> direktorijas norādi varēja veikt arī ar ~/rubbish/garbage.txt, kur ~/ novada uz mājas direktoriju
**echo _ļoti svarīga informācija_ > saglaba.txt** - izveido failu saglaba.txt ar doto tekstu _ļoti svarīga informācija_
**rm saglaba.txt** - dzēš saglaba.txt
**rm sag* - (* -wild card)**- dzēš visus failus ar faila sākumu sag- , neatkarīgi no faila paplašinājuma
**cp** - kopēt failu
**cp saglaba.txt nevajag.txt** - izveido saglaba.txt kopiju ar nosaukumu nevajag.txt
-> tāpat var kopē failus uz krātuvi, piem cp saglaba.txt /media/sda1/ , kur fails tiks iekopēts norādītajā direktorijā
**mv** - pārcelt failu citā direktorijā, norādot jauno direktoriju
**mv saglaba.txt nevajag.txt** - aizstāj saglaba.txt ar tādu pašu failu ar nosaukumu nevajag.txt, burtiski - pārsauc (noskaidrot, vai maina reģistru)
**chomd** - maina tiesības failiem failam
vairāk par chmod - https://en.wikipedia.org/wiki/Chmod -automatic!
[Wikipedia](https://en.wikipedia.org/wiki/Chmod)

MISC
uname - parāda OS nosaukumu
uname -a - parāda pilno OS nosaukumu
echo $0 - parāda atrašanās vietas adresi
whoami - parāda lietotāja vārdu
who - informācija par lietotāju
man - ar komandu aiz tā parāda komandas skaidrojumu
history - parāda iepriekš lietotās komandas
sh - izslēdz shell
pwd - parāda adresi
history - parāda komandu vēsturi
~ - home/user apgabals
cat (faila nosaukums) - nolasa faila saturu
hexdump -C (faila nosaukums) - izdrukā faila simbolus hex sistēmā
echo (teksts) >> (faila nosaukums) - pievieno failam tekstu
0a - komandas pārcelšanas simbols
nano - atver nano
tree - parāda dir tree
PATH=$PATH:~ - pievieno jaunu PATH
git clone htpps://github.com/ArtursZeibots/RMB0AZ - nokopē manu repozitoriju
nano first.c - izveido un atver failu c valodā
gcc first.c - kompilē skriptu c valodā
echo $? - parāda pēdējā procesa rezultātu (0 = nav kļūdu)
gcc first.c -o second.out - kompilē skriptu, mainot nosaukumu
history > history_20200928.txt - izdrukā komandu vēsturi failā
