//Loģiskās operācijas
// Salīdzināšanas aoperācijas: <, >, <=, >=, ==, !=
//loģiskās operācijas pa bitiem
#include <stdio.h>
#include <time.h>

int main()
{
char a = 5;
char b = 5;

char c; 

c= a<b;
printf("%d < %d = %d\n",a,b,c);
c= a>b;
printf("%d > %d = %d\n",a,b,c);
c= a<=b;
printf("%d <= %d = %d\n",a,b,c);
c= a>=b;
printf("%d >= %d = %d\n",a,b,c);
c= a==b;
printf("%d == %d = %d\n",a,b,c);
c= a!=b;
printf("%d != %d = %d\n",a,b,c);

b=4;
c= a<b;
printf("%d < %d = %d\n",a,b,c);
c= a>b;
printf("%d > %d = %d\n",a,b,c);
c= a<=b;
printf("%d <= %d = %d\n",a,b,c);
c= a>=b;
printf("%d >= %d = %d\n",a,b,c);
c= a==b;
printf("%d == %d = %d\n",a,b,c);
c= a!=b;
printf("%d != %d = %d\n",a,b,c);

printf("Salīdzināšans operācijas datu tipa izmērs (operandi ar char datu tipu): %d\n", sizeof(a>0));
printf("Salīdzināšans operācijas datu tipa izmērs (operandi ar int datu tipu): %d\n", sizeof(5>4));

printf("5>6 && 5!=6 = %d\n",(5>6)&&(5!=6));
printf("5<6 && 5!=6 = %d\n",(5<6)&&(5!=6));

printf("5>6 || 5!=6 = %d\n",(5>6)||(5!=6));
printf("5<6 || 5!=6 = %d\n",(5<6)||(5!=6));

printf("5&6 = %d\n",5&6)); //*0000 0101 & 0000 0110 = 0000 0100 printf("5 | 6 = %d\n",5 | 6)); //0000 0101 | 0000 0110 = 0000 0111 printf("~6 = %d\n",~6);// 0000 0110 = (1)111 1001 -> -000 0110 +1 -> 
-000 0111 -> -7 *//

//a - 40 000 un b - 100 000 -> a*b = 4 000 000 000
//izmantojot bīdīšana pa labi pa kreisi jāataino char binārais kods - dec to bin

return 0;
}
//0000 0101 & 0000 0110 = 0000 0100

