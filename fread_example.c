# include  <stdio.h>
# include <stdlib.h>

int main(){
FILE * pFile;
long lSize;
int * buffer;
size_t result;

pFile=fopen("intbuferis.bin", "rb");
if  (pFile==NULL) {
fputs("Faila kļūda",stderr); 
exit(1);
}

// Noskaidrojam faila izmēru:
fseek (pFile, 0, SEEK_END);//Novietojam kursoru faila sākumā - 0, pārvietojam uz beigām ar SEEK_END
lSize=ftell (pFile);//Nosakam faila izmēru baitos, tāpēc arī nepieciešams long  formāts - var pārsniegt int  ietilpināmo skaitli
rewind (pFile); //Aizbīdam kursoru atpakaļ uz sākumu

// Iedalam atmiņu visam faila izmēram
//buffer=(int*) malloc (sizeof(int)*lsize);// šāda metode iedala 1 baita izmēru katram baitam, šo soli loģiski var izslēgt, jo lSize jau ir nepiecieāmo baitu skaits ->pārrakstot:
buffer=(int*) malloc (lSize); //malloc - iebūvētā funkcija http://cplusplus.com/reference/cstdlib/malloc/?kw=malloc
if (buffer==NULL) {
fputs("Atmiņas kļūda",stderr);
exit (2);
}

//Iekopējam failu atmiņā:
result = fread(buffer, sizeof(int), lSize/sizeof(int), pFile);
if (result != lSize/sizeof(int)) {
fputs("Lasīšanas kļūda", stderr);
exit (3);
}

//Dokuments ir ielādēts atmiņas buferī
for (int  i=0;i< result; i++)
   printf("%d\n",buffer[i]);
//Aizveram failu, attīram atmiņu izbeidzam programmu
fclose(pFile);
free (buffer);

return 0;
}

