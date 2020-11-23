/* fgetc example: money counter */
#include <stdio.h>
int main ()
{
  FILE * pFile;
  int c;
  int n = 0;
  pFile=fopen ("testa.txt","r");
  if (pFile==NULL) perror ("Kļūda atverot dokumentu");
  else
  {
    do {
      c = fgetc (pFile);
      if (c == '$') n++;
    } while (c != EOF);// EOF - faile beigu pazīme
    fclose (pFile);
    printf ("Dokuments satur %d dolāru zīmes ($).\n",n);
  }
  return 0;
}
