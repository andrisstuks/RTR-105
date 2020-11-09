#include <stdio.h>

int main(){
int a =5;
int *pa =&a;
int *ppa= &pa;

printf("mainīgā vērtība %d\n",a);
printf("mainīgā adrese: %p\n",pa);
printf("adreses adrese %p\n",ppa);
printf("mainīgā adrese: %p\n",*ppa);
printf("mainīgā vērtība: %d\n",**ppa);

return 0;

}
