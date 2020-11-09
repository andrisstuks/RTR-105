#include <stdio.h>

int main(){
int a=5;
int *pa =&a; //šis ir mainģais adrešu glabāšanai, kur p ir adreses pointeris

printf("adreses vertiba pirms izmainjas %p\n",pa);
printf("mainīgā vērtība pirms izmaiņām: %d\n\n",a);

*pa = *pa+1;

printf("adreses vertiba pēc izmaiņas %p\n",pa);
printf("mainīgā vērtība pēc saskaitīšanas: %d\n\n",a);

return 0;

}

