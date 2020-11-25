//Šo iznākumu nav jēga skatīties ar cat, ar hexdump -C parāda lsb->msb, atainojot jāpievērš vērība
/* fwrite example : write buffer */
#include <stdio.h>

int main ()
{
  FILE * pFile;//Norāde uz failu
//  char buffer[] = { 'x' , 'y' , 'z' };//char  datu masīvs
  int buffer[]={101,202,303};
  pFile = fopen ("intbuferis.bin", "wb");//Būs bin fails
  //fwrite (buffer , sizeof(char), sizeof(buffer), pFile);//rakstīsim
  fwrite (buffer , 1, sizeof(buffer), pFile);//mazāks sakarīgs pieraksts pa baitam 
  fclose (pFile);
  return 0;
}
