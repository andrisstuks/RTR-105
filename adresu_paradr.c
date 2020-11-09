#include <stdio.h>

void test(int *paa){
printf("mainīgā adrese no test - %p\n", paa);
printf("mainīgā vērtība no test: %d\n\n", *paa);
*paa=*paa +10;
}

int main(){
int a =5;
int *pa =&a;


printf("mainīgā vērtība no main pirms test: %d\n\n",a);
printf("mainīgā adrese no main pirms test: %p\n",pa);
test(pa);
printf("mainīgā vērtība no main pēc testa: %d\n",a);
printf("mainīgā adreseno main testa: %p\n\n",pa);


return 0;

}
