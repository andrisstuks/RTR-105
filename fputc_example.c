 /* fputc example: alphabet writer */
#include <stdio.h>

int main ()
{
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
