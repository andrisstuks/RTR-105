#include <stdio.h>

int main(){
char a = 'A';
int b =5;
double c =3.6;

printf("sizeof f-cija izmērs %lu\n",sizeof(sizeof(a)));
printf("sizeof f-cija izmērs %lu\n",sizeof(sizeof(b)));
printf("sizeof f-cija izmērs %lu\n\n",sizeof(sizeof(c)));

printf("a mainīgā adrese: %p\n",&a);
printf("a mainīga adreses izmērs: %lu\n",sizeof(&a));
printf("a Vērtība pēc adreses: %d\n",*(&a));
printf("a Vērtības izmērs baitos pec adreses: %lu\n\n",sizeof(*(&a)));

printf("b mainīgā adrese: %p\n",&b);
printf("b mainīga adreses izmērs: %lu\n",sizeof(&b));
printf("b Vērtība pēc adreses: %d\n",*(&b));
printf("b Vērtības izmērs baitos pec adreses: %lu\n\n",sizeof(*(&b)));

printf("c mainīgā adrese: %p\n",&c);
printf("c mainīga adreses izmērs: %lu\n",sizeof(&c));
printf("c Vērtība pēc adreses: %.1f\n",*(&c));
printf("c Vērtības izmērs baitos pec adreses: %lu\n\n",sizeof(*(&c)));

return 0;
}
