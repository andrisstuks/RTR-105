# RTR-105
Datormācība (pamatkurss) elektroniskā klade

#### ls
|komanda|apraksts|
|-------|--------|
|ls| komandai argumentu apzīmējumu kārtībai nav nozīmes(-a, -l, -t, -r) un tos var apvienot|
|ls -lart| būs tas pats kas ls -l -a -r -t|
|ls| - visi faili un drektorijas . direktorijā  |
|ls -F| - parāda datu tipu, / -direktorija, @ -links, * -izpildāmais fails|
|ls -l| - parāda failu un direktoriju sarakstu ar to tiesībām, savienojumiem, piederību, lietotāja grupu, izmēru baitos, pēdējo izmaiņu datumu un nosaukumu ar paplaišinājumu|
|ls -lh| - parāda līdzīgi kā -l, bet ar izmēru K, M vai G baitu paplašinājumu|
|ls Desktop/| - parāda /Desktop adrešu sarakstu|
|ls -a| - parāda pilnu failu un direktoriju sarakstu|
|ls -al| - parāda pilnu failu un direktoriju sarakstu, ieskaitot slēptos failus un direktorijas ar tiesībām un izmēru baitos|
|ls -lt| - parāda failu un direktoriju sarakstu ar to tiesībām, piederību un izmēru baitos, šķirojot pēc datuma dilstoši|
|ls -lrt| - tas pats kas lt, tikai augoši, īpaši ērti, ja pievienojam kādu failu, ko gribam izpildīt - tas pēc attainojuma būs blakus aktīvajam kursoram, t.i. sraksta apakšā
|ls -lart| - visi faili ieskiatot slēptos, sašķiroti pēc laika augošā secībā|

#### cd
|komanda|apraksts|
|-------|--------|
|cd ..| - atpakaļ|
|cd ~| (tilde) - pārvieto uz mājas direktoriju|
|cd home/user| - pārvieto uz mājas diektorijas adresi|
|cd /| - pārvieto uz root adresi|
|cd -|  -pārvieto uz mājas direktoriju|


#### Darbības ar failiem un direktorijām
|komanda|apraksts|
|-------|--------|
|mkdir| - izveidot direktoriju, saīsinājums no make directory|
|mkdir -p /home/user/svarigas/lietas/seit| -Lai izveidotu vairāku direktoriju dziļu direktoriju, izveidojot neesošās direktorijas pa ceļam|
|rmdir| - izdzēst direktoriju, saīsinājums no remove directory, izdzēš tikai tukšu direktoriju|
|rm -rf| - izdzēsīs direktoriju arī ar writeprotected failiem un visām direktorijām norādītajā direktorijā|
|touch| - rada tukšu failu|
|touch sample.txt| - rada failu ar nosaukumu sample un faila paplašinājumu .txt direktorijā, kurā atrodamies|
|touch /home/user/rubbish/garbage.txt| - izveido garbage.txt failu direktorijā /home/user/rubbish/|
||-> direktorijas norādi varēja veikt arī ar ~/rubbish/garbage.txt, kur ~/ novada uz mājas direktoriju|
|echo ļoti svarīga informācija > saglaba.txt| - izveido failu saglaba.txt ar doto tekstu _ļoti svarīga informācija_|
|cat random_fails.txt| - nolasa _random_fails.txt_ tesktu|
|hexdump -C random_fails.txt| - izdrukā faila simbolus hex sistēmā|
|nano| - atver nano teksta editoru|
|nano random_fails.txt| atver _random_fails.txt_ , ja fails nepastāv - rada teksta logu, un beidzot darbu nano, saglabā failu ar norādīto nosaukumu|
|rm saglaba.txt| - dzēš saglaba.txt|
|rm sag*| - (* -wild card)- dzēš visus failus ar faila sākumu sag- , neatkarīgi no faila paplašinājuma|
|cp |- kopēt failu|
|cp saglaba.txt nevajag.txt| - izveido saglaba.txt kopiju ar nosaukumu nevajag.txt|
||-> tāpat var kopē failus uz krātuvi, piem cp saglaba.txt /media/sda1/ , kur fails tiks iekopēts norādītajā direktorijā|
|mv |- pārcelt failu citā direktorijā, norādot jauno direktoriju|
|mv saglaba.txt nevajag.txt| - aizstāj saglaba.txt ar tādu pašu failu ar nosaukumu nevajag.txt, burtiski - pārsauc (noskaidrot, vai maina reģistru)|
|chomd| - maina tiesības failiem failam. Par to - atsevišķa sadaļa|

-> vairāk par chmod - [Wikipedia](https://en.wikipedia.org/wiki/Chmod)


#### Informācija par iekārtu
uname - parāda OS nosaukumu

ar uname var pielietot sekojošsas opcijas
|komanda|apraksts|
|-------|--------|
|-a vai --all| - parāda visu informāciju, izņemot procesora un platformas informāciju,|
|-n vai --nodename| - norāda tīkla iekārtas nosaukumu|
|-p vai --processor| - procesora informācija|
|-i vai --hardware-platform| - norāda platformas informāciju|
|-o vai --operating-system |- norāda operētājsistēmu|
|-m vai --machine| - norāda arhitektūras nosaukumu|
|-s vai --kernel-name| - kodola informācija |
|-r vai --kernel-release| - kodola relīze|
|-v vai --kernel-version| - kodola versija|


#### Atļaujas

Aļauju tipi:
```
r -> read jeb lasīt
w -> write jeb rakstīt/izmainīt
x ->execute jeb izpildīt
````
Svarīgi zināt lietotāja grupu, to var pārbaudīt ar komandu ```groups``` vai ```id -Gn```. Jebkuru lietotāju var pārbaudīt ar komandu ```groups usnm``` kur usnm vietā rakstam lietotāja vārdu

Lietotāju kategorijas:
```
u - User jeb lietotājs, kuram "pieder" fails jeb direktorija. Lietotājs pieder vismaz vienai grupai
g - Group jeb grupa, automātiski piešķir pieeju u jeb lietotājiem, kas ir tajā grupā
o - Other jeb citi, autokātiski pie
a - All jeb visi
```

Atšķirības starp failu un direktoriju atļaujām
|Atļauja|Fails|Direktorija|
|-------|-----|-----------|
|r|Atļauj lasīt failu|Atļauj lasīt failu nosaukumus direktorijā, bet ne papildus informāciju|
|w|Atļauj mainīt failu|Atļauj mainīt ierakstus direktorijā un mainīt failus direktorijā|
|x|Atļauj izpildīt failu|Atļauj pieeju mapes saturam un satura metadatiem, visu ko var redzēt ar ls -lart|

Pārbaudot ar ```ls -l```, norādītais atļauju apraksts -rwxr--rx- tulkojams kā 
|-|rxw|rx--|r-|
|tips|īpašnieka tiesības|Grupas tiesības|citu tiesības|

Atkarībā no Linux "garšiņas", atļauju piešķiršana var nedaudz atšķirties, bet pamatā tā nitek sekojoši
|Operators|Nozīme|
|-----|-----|
|chmod|change mode komanda|
|ugoa|Lietotāja kategorija - user, grou, other, all (sk. iepriekš)|
|=-+|Pievienot, noņem vai pielīdzināt atļauju|
|rwx|lasīt, rakstīt, izpildīt|

Piemēri:
|Komanda|Apraksts|
|-------|--------|
|chmod a+x file.out| Piešķirs lietotājam, grupai un citiem izpildīt šo failu|
|chmod u-x file.out| Noņems lietotājam faila izpildes tiesības, atstājot tās grupai un citiem|
|chmod u+wx,g+w,a-r some.py| vienlaicīgi piešķirs lietotājam tiesības modificēt un izpildīt failu, grupai ļau modificēt failu, kamēr citiem neļaus apskatīt failu|
|chmod a=rwx some.py| Piešķirs visiem rasīšanas, rakstīšanas un izpildes tiesības|
||Jāņem vērā pāris dīvainības|
|chmod u=rwx,g=,a= some.py| Noņems visiem lietotājiem visas tiesības, kamēr|
|chmod a=,g=,u=rwx some.py| Noņems visas izpildes tiesības visiem un grupai, un piešķirs visas tiesības lietotājam|
||Attiecīgi noņemot visas tiesības visie, nav nepieciešams noņemt rupai tiesības, jo grupa ir visu apakšgrupa.|

Atļaujām var izmantot arī ciparu formātā, kur cipari tiek interpretēti oktālā sistēmā
|r|w|x|Nozīme|
|-|-|-|------|
|0|0|0|Vērtība ja deaktivizēts|
|1|1|1|Binārā vērtība ja aktivizēts|
|4|2|1|Base 10 vērtība ja aktivizēts|

Pastāv 8 iespējamās vērtības atļaujām:
|Octal|Bin|Apzīmējums|Apraksts|
|-----|---|----------|--------|
|0|0|---|Nav atļaujas|
|1|1|--x|Tikai izpildīt|
|2|10|-w-|Tikai rakstīt|
|3|11|-wx|Rakstīt un izpildīt (2+1)|
|4|100|r--|Tikai lasāms|
|5|101|r-x|Lasāms un izpildāms (4+1)|
|6|110|rw-|Lasāms un rakstāms (4+2)|
|7|111|rwx|Lasāms, rakstāms un izpildāms (4+2+1)|

Grupējot pēc nozīmes:
| |u|g|o|
|--|--|--|--|
|simboliski|rwx|r-x|r--|
|Bināri|111|101|100|
|Decimāli|7|5|4|

Biežāk pielietotās atļaujas:
|Simboliski|Oktāli|
|----------|------|
|-rwx------|700|
|-rwxr-x-r-x|755|
|-rw-rw-r--|664|
|-rw-rw----|660|
|-rw-r--r--|644|

777 kods nav tas labākais, jo tas ļauj jebkuram kas ir sistēma izpildīt šo failu, tādējādi paverot iespēju ļaunatūrai sākotnēt failu vai programmas izpildi. Šāda koda izmatošanu vēlams aizstāt ar grupas izveidi lietotājiem, kuriem nepieciešama ši faila vai direktorijas izmantošana, un tad ierobežojot pilnu piekļuvi šim failam noteiktajai grupai.

Faila piederību grupai var mainīt ar komandu ```chgrp```, norādot vēlamo grupu un faila nosaukumu, kuram mainam piuederību grupai, piemēram - ```chgrp students atzimes.txt``` piešķirs pieeju lietotāju grupai```students``` pieeju failam ```atzimes.txt```, pēcāk ar komandu ```chmod g+rw atzimes.txt``` šai grupai tiks piešķirtas tiesības lasīt un modificēt šo failu

#### Failu un direktoriju izveide un ```umask```

Izveidojot failu vai direktoriju, tai tiek pieškirtas noklusējuma atļaujas 777 direktorijām un 666 failiem. Tas ir tiesa līdz brīdim, ja netiek pielietota ```umask``` komanda.
```umask``` komandas būtība ir samazināt jaunveidoto failu un direktoriju noklusēto atļauju. ```umask``` var definēt sistēmas administrators visai sistēmai vienādi, un var mainīt atsevišķi katram lietotājam. Komandas apraksts ```umask [-S] [mode]```, kur -S izmanto simboliskai piešķiršanai, bez -S izmanto ```mode``` norādot piemēram ```022```.
```umask``` piemēri:
|Apraksts|Direktorija|Fails|
|--------|-----------|-----|
|Noklusējuma atļauja|777|666|
|atņemam ```umask``` -piemērots lietotājam|-022|-022|
|Izveidojot atļauja|755|644|
||||
|Noklusējuma atļauja|777|666|
|atņemam ```umask``` - piemērots grupai|-002|-002|
|Izveidojot atļauja|775|664|

Biežāk lietotās ```umask``` kombinācijas:
* 022
* 002
* 077
* 007

Kur atņemot 7 no 6, rezultāts ir -1, kas tiek interpretēts kā 0 un attiecīgajai grupai visas atļaujas tiek mainītas uz 0

```umask``` uzstādījumus var pārbaudīt, ievadot komandu ```umask``` bez argumentiem, vai ar argumentu -S```umask -S```, kur pirmajā gadījumā atbilde būs līdzīga ```0022```, un otrajā - ```u=rwx,g=rx,o=rx```. Ievērojiet, ka parbaudot atbildi oktāli, mēs redzam 4 simbolus 3 simbolu vietā, tas ir sastīts ar to, ka pirmais simbols raksturo speciālās klases:

* setuid
* setgid
* sticky

```umask 0022``` ir tas pats kas ```umask 022```

#### ECHO
|komanda|apraksts|
|-------|--------|
|echo $0| - parāda atrašanās vietu relatīvi darbībai. Atrodoties skriptā, šī komanda atgriezīs skripta nosaukumu|
|echo $?| - parāda pēdējā procesa izpildes rezultātu |
|echo $OLDPWD| - parāda iepriekšējo aktīvo direktoriju|
|echo _ļoti svarīgs teksts_ >> random_fails.txt| - pievieno norādīto tekstu norādītajam failam|

-> par _echo_ var atrast [Tecmint](https://www.tecmint.com/echo-command-in-linux/)

#### Noderīga informācija
|komanda|apraksts|
|-------|--------|
|whoami| - parāda lietotāja vārdu|
|who| - saīsināta informācija par ielogotiem lietotājiem|
|w| - laiku, datora uptime, ielogoto lietotāju skaitu un sarakstu|
|man| - ar komandu aiz tā parāda komandas skaidrojumu|
|pwd| - _present working directory_ - parāda patreizējo . direktoriju|
|tree| - parāda failu un direktoriju koku|
|tree -d| - parāda tikai tree. Iekš Raspberry pi (debian) nestrādā|


#### Pievienot PATH
|komanda|apraksts|
|-------|--------|
|PATH=$PATH|:~- pievieno norādīto direktoriju PATH|

#### Programmas rakstīšana nano editorā, kompilēšana
|komanda|apraksts|
|-------|--------|
|nano random.c |- atver norādīto failu, ja fails nepastāv, saglabājot izveido failu ar norādīto nosaukumu un .c paplašinājumu (C valodas fails)|
|gcc random.c| - kompilē skriptu par izpildāmu failu, pēc noklusējuma _a.out_|
|gcc random.c -o strict.out| - kompilē skriptu par izpildāmu failu, piešķirot nosaukumu _strict.out_|


#### Darba beigšana, komandu saglabāšana
|komanda|apraksts|
|-------|--------|
|clear|Attīra termināļa logu|
|history| - parāda iepriekš lietotās komandas|
|history > darbibu_vesture.txt| - saglabā visu darbību vēsturi _darbibu_vesture.txt_ failā.|
|exit| - izeja no sistēmas|
|sh| - izslēdz shell

