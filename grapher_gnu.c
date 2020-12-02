 /*Ar šo ģenerēsim teksta failu atēlošanai */
#include <stdio.h>

int main ()
{

int a=0; //int a definēšana un vērtība
int b=0; // int b definēšana un piešķiršana
int rangelen=0;

printf("Lūdzu ievadiet A robežu x:\n");
scanf ("%d", &a);
printf("Lūdzu ievadi B robežu x:\n");
scanf("%d", &b);
printf("Lūdzu ievadiet punktu skaitu, ne mazāku par 2:\n");//Jo vienkārši nevar būt mazāk par 2 punktiem, jo jau ir sākumpunkts un beigu punkts

  FILE * pFile;
  char c;

  pFile = fopen ("alfabets.txt","w");
  if (pFile!=NULL) { //Šeit izteiksme - ja fails nav null nozīmē ka tas ir atvērts, kļūdas gadījumā neko nepateiks, pārrakstīs esošo failu

    for (c = 'A' ; c <= 'Z' ; c++)
      fputc ( c , pFile );//Raksta pa vienam  simbolam failā
//Sava modifikācija lai pārceltu kursoru jaunā rindā
fputc ('\n',pFile); 
// Modifikācijas beigas
    fclose (pFile);
  }
  return 0;
}
