// Cikls for(sākuma vērtības; izteiksme; cikla mainīgo izmaiņas)
//	{
//		izdaram darbību
//	} līdz brīdim, kad nosacījums ir izpildījies
//
//tātad for(sākuma_vērtība; izteiksme; cikla mainīgo izmaiņas)->izpildam vienu darbību
//
//https://www.tutorialspoint.com/cprogramming/c_do_while_loop.htm
#include <stdio.h>
#include <math.h>

int main()
{
//deklarējam un piešķiram mainīgos
double a=0.35;
double s=0.05;
double prec_range=s/2; //
do{
printf("Sākot iterāciju a= %.2f un peldošajā %e\n",a,a);
a+=s;
printf("a =%.20f (peldošais= %e)\n",a,a);
}while(fabs(a-1.0)>prec_range);

printf("Pēc cikla a=%.2f un ar peldošo %e\n",a,a);

return 0;
}

