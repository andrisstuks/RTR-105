#include <stdio.h>

int main()
{
char a=5;
char b=10;
char c = a + b;
printf("%d + %d = %d\n",a,b,c);
printf("a+b=%d\n",a+b);
char d= a/b;
printf("%d / %d = %d\n",a,b,c);
float dd = a / b; //cahr/char -> char
printf("%d / %d = %d\n",a,b,dd);
printf("%d / %d = %f\n",a,b,dd);//nebūs zīme aiz komata, jo char nesaur zīmes aiz komata, un zīmes aiz komata pazaudēšana notiek jau dalīšanā
float aa = 5;
dd = aa / b; // float dalīts ar char
printf("%f / %d = %f\n",aa,b,dd);
d =aa/b;//float/char -> float -> char
dd=d;
printf("%f / %d = %f\n",aa,b,dd);
printf("(float)%d / %d = %f\n", a,b,(float)a/b);// vienlaikus falam un mainam datu tipu (float)
printf("(float)%d / %d izmērs baitos - %d\n", sizeof(float)a/b);// vienlaikus falam un mainam datu tipu (float)
printf("1. * a / d -rezultāta izmērs baitos - %d\n",sizeof(1*a/b);// vienlaikus falam un mainam datu tipu (float)
printf("1. * %d / %d = %f\n",a,b,1.*a/b);// vienlaikus falam un mainam datu tipu (float)
//1 - vesela tipa konstante (int)
//1. - reāla datu tipa konstante(double
//(char)1
//(float)1
///

//Atlikums no dalījuma
//%
//piemērojama tikai vesela tipa skaitļiem
char e = a % b;
printf("%d %c %d = %d\n",a,37,b,e);

printf("%d %c %d = %d\n",a,0x25,b,e);

printf("%d %c %d = %d\n",a,'%',b,e);
printf("%d %c %d = %d\n",a,'%',b,e);
printf("%d %c %d = %d\n",199,'%',b,e);



return 0;
}
//Operācijas
//=,-,*,/,%
// Operācijai ir rezultāts, operācijas rezultātam vienmēr ir  kaut kāds datu tips
//Operācijas rezutlāta datu tips ir "plašākais" datu tips kas piedalās operāciā

