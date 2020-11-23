/* fputs example */
#include <stdio.h>

int main ()
{
   FILE * pFile;
   char sentence [256];

   printf ("Ievadi teikumu pievienošanai: ");
   fgets (sentence,256,stdin);
   pFile = fopen ("testa.txt","a");
   fputs (sentence,pFile);
   fclose (pFile);
   return 0;
}
