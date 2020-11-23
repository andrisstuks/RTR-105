/* fopen example */
/* Šāds pārraksta esošo informāciju failā, varētu izmantot pēdējā statusa saglabāšanai */
#include <stdio.h>
int main ()
{
  FILE * pFile;
  pFile = fopen ("testa.txt","w");
  if (pFile!=NULL)
  {
    fputs ("fopen example ar papildinajumu parbaudei\n",pFile);
    fclose (pFile);
  }
  return 0;
}
