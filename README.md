# RTR-105
Datormācība (pamatkurss) elektroniskā klade

####ls 
**ls** - visi faili un drektorijas . direktorijā
**ls -l** - parāda failu un direktoriju sarakstu ar to tiesībām, piederību un izmēru baitos
**ls -lh** - parāda līdzīgi kā -l, bet ar izmēru K, M vai G baitu paplašinājumu
**ls Desktop/** - parāda /Desktop adrešu sarakstu
**ls -a** - parāda pilnu failu un direktoriju sarakstu
**ls -al** - parāda pilnu failu un direktoriju sarakstu, ieskaitot slēptos failus un direktorijas ar tiesībām un izmēru baitos
**ls -lt** - parāda failu un direktoriju sarakstu ar to tiesībām, piederību un izmēru baitos, šķirojot pēc datuma dilstoši
**ls -lrt** - tas pats kas lt, tikai augoši, īpaši ērti, ja pievienojam kādu failu, ko gribam izpildīt - tas pēc attainojuma būs blakus aktīvajam kursoram, t.i. sraksta apakšā

####cd
**cd ..** - atpakaļ
**cd ~** (tilde) - pārvieto uz mājas direktoriju
**cd home/user** - pārvieto uz mājas diektorijas adresi
**cd /** - pārvieto uz root adresi

####Darbības ar failiem un direktorijām
**mkdir** - izveidot direktoriju, saīsinājums no make directory
**rmdir** - izdžest direktoriju, saīsinājums no remove directory
**touch** - rada tukšu failu
**touch sample.txt** - rada failu ar nosaukumu sample un faila paplašinājumu .txt direktorijā, kurā atrodamies
**touch /home/user/rubbish/garbage.txt** - izveido garbage.txt failu direktorijā /home/user/rubbish/
-> direktorijas norādi varēja veikt arī ar ~/rubbish/garbage.txt, kur ~/ novada uz mājas direktoriju
**echo _ļoti svarīga informācija_ > saglaba.txt** - izveido failu saglaba.txt ar doto tekstu _ļoti svarīga informācija_
**cat random_fails.txt** - nolasa _random_fails.txt_ tesktu
**hexdump -C random_fails.txt** - izdrukā faila simbolus hex sistēmā
**nano** - atver nano teksta editoru
**nano random_fails.txt** atver _random_fails.txt_ , ja fails nepastāv - rada teksta logu, un beidzot darbu nano, saglabā failu ar norādīto nosaukumu
**rm saglaba.txt** - dzēš saglaba.txt
**rm sag* - (* -wild card)**- dzēš visus failus ar faila sākumu sag- , neatkarīgi no faila paplašinājuma
**cp** - kopēt failu
**cp saglaba.txt nevajag.txt** - izveido saglaba.txt kopiju ar nosaukumu nevajag.txt
-> tāpat var kopē failus uz krātuvi, piem cp saglaba.txt /media/sda1/ , kur fails tiks iekopēts norādītajā direktorijā
**mv** - pārcelt failu citā direktorijā, norādot jauno direktoriju
**mv saglaba.txt nevajag.txt** - aizstāj saglaba.txt ar tādu pašu failu ar nosaukumu nevajag.txt, burtiski - pārsauc (noskaidrot, vai maina reģistru)
**chomd** - maina tiesības failiem failam
-> vairāk par chmod - [Wikipedia](https://en.wikipedia.org/wiki/Chmod)

####Informācija par iekārtu
uname - parāda OS nosaukumu
ar uname var pielietot sekojošsas opcijas
```
-a vai --all - parāda visu informāciju, izņemot procesora un platformas informāciju,
-n vai --nodename - norāda tīkla iekārtas nosaukumu
-p vai --processor - procesora informācija
-i vai --hardware-platform - norāda platformas informāciju
-o vai --operating-system - norāda operētājsistēmu
-m vai --machine - norāda arhitektūras nosaukumu
-s vai --kernel-name - kodola informācija 
-r vai --kernel-release - kodola relīze
-v vai --kernel-version - kodola versija
```

####ECHO
**echo $0** - parāda atrašanās vietu relatīvi darbībai. Atrodoties skriptā, šī komanda atgriezīs skripta nosaukumu, 
**echo $?** - parāda pēdējā procesa izpildes rezultātu 
**echo _ļoti svarīgs teksts_ >> random_fails.txt** - pievieno norādīto tekstu norādītajam failam
-> par _echo_ var atrast [Tecmint](https://www.tecmint.com/echo-command-in-linux/)

####Noderīga informācija
**whoami** - parāda lietotāja vārdu
**who** - saīsināta informācija par ielogotiem lietotājiem
**w** - laiku, datora uptime, ielogoto lietotāju skaitu un sarakstu
**man** - ar komandu aiz tā parāda komandas skaidrojumu
**pwd** - _present working directory_ - parāda patreizējo . direktoriju
**tree** - parāda dir tree. Iekš Raspberry pi (debian) nestrādā

####Pievienot PATH
**PATH=$PATH:~**- pievieno norādīto direktoriju PATH

####Programmas rakstīšana nano editorā, kompilēšana
**nano random.c** - atver norādīto failu, ja fails nepastāv, saglabājot izveido failu ar norādīto nosaukumu un .c paplašinājumu (C valodas fails)
**gcc random.c** - kompilē skriptu par izpildāmu failu, pēc noklusējuma _a.out_
**gcc random.c -o strict.out** - kompilē skriptu par izpildāmu failu, piešķirot nosaukumu _strict.out_

####Darba beigšana, komandu saglabāšana
**history** - parāda iepriekš lietotās komandas
**history > darbibu_vesture.txt** - saglabā visu darbību vēsturi _darbibu_vesture.txt_ failā.
**sh** - izslēdz shell

####Raspberry Pi lietotāja administrēšana, SSH maiņa

