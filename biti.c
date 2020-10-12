//Bitu operācijas
//bitu operācijas: << un >>

#include <stdio.h>
#include <time.h>

int main()
{
char a = 5;// 0000 0101
char b = 1;
char c = a << b; // 0|00 0101 << 1 -> 0000 101|0 ( 0000 1010)
printf("%d << %d = %d\n",a,b,c);
b=2;
c = a << b;// 00|00 0101 << 2 -> 0001 01|00 (0001 0100)
printf("%d << %d = %d\n", a,b,c);
b=3;
c= a << b; // 000|0 0101 << 3 -> 0010 1|000 (0010 1000)
printf("%d << %d = %d\n",a,b,c);
// Šī ir pozicionālā skaitīšanas sistēma - cipara vertība ir atkarīga no vietas, kurā vērtībā stāv
// Šajā gadījumā 5 <<1  =1-, jo 5 * 2^1= 10
//5 << 2, jo 5 * 2^2 = 5 * 4 = 20
//5 << 3 = 5 8 2^3 = 5 * 8= 40
clock_t begin = clock();
c = a << b; //0000 0|101 <<5 -> 1010 000
clock_t end = clock();
double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
printf("Reizināšna ar 2 ar << operāciju: %g\n", time_spent);
printf("%d << %d = %d\n", a,b,c);

begin = clock();
c = a*2*2*2*2*2;
end = clock();
time_spent= (double)(end-begin) / CLOCKS_PER_SEC;
printf("Reizināšana ar 2 ar * operāciju: %g\n", time_spent);
printf("%d *2 = %d\n",a,c);



return 0;
}
