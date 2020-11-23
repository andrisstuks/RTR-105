/* fprintf example */
#include <stdio.h>

int main ()
{
   FILE * pFile;
   int n;
   char name [100];

   pFile = fopen ("testa.txt","w");
   for (n=0 ; n<3 ; n++)
   {
     puts ("Lūdzu ievadiet savu vārdu: ");
     gets (name); //Bīstams izmantošanai, jo nepievēŗš uzmanību string izmēram un var pārrakstīt citus adrešu apgabalus
     fprintf (pFile, "Vārds %d [%-10.10s]\n",n+1,name);
   }
   fclose (pFile);

   return 0;
}
