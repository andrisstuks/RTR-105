/* fclose example */
#include <stdio.h>
int main ()
{
  FILE * pFile;
  pFile = fopen ("testa.txt","wt");
  fprintf (pFile, "fclose example lai redzam ka mainas\n");
  fclose (pFile);
  return 0;
}
