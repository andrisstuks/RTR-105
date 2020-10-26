//cikls  while(izteiksmei){darbības bloks}
//while(izteiksme) viena_darbiba;
//	izteiksmes rezultats - vai nu 0 vai !0
//	izpildās, kad vertiba==True jeb !0

#include <stdio.h>

int main()
{
while (0)
{
printf("Šo neattēlos nemaz\n");
}
while(1)
{//lai apstādinātu loop, -> CTRL+C
printf("Šo mauc bezgalīgi\n");
// ja gribam pārtraukt darbību, pēc vienas izpildes varam pārtraukt cikla izpildīšanu
break;//Izmet no cikla
}
double a=3.5e-1; //matemātikā šis skaitlis ir 0,35, tas ir skaitlis ar fiksēto punktu
//3.5e-1 ir skaitlis ar peldošo puntu, kuru apzīmē 3,5* 10**-1=0.35 
//skaitam ar range funkciju, solim norādam atsevišķu mainīgo
double s=0.5e-2;
while(a<=1)//loģiskā pārbaude. Ja rakstītu izteiksmi a!=1, tad neapstāsies, jo bitu un skaiļu reprezentācija skaitļos ir neprecīza
//ja grib apstāties precīzi pie konkŗeta skaitļa - 
//pieraksta  
// double precis_range=s/2  kur esam definējuši precizitāti kādā vēlamies apstāties
// while ( fabs(a-1.0) >precis_range)
{
printf("Vērtības pirks sākuma- %.20f (peldošais %e)\n",a,a);
printf("a = %f (vai peldošo punktu %g)\n",a,a);
a+=s;//saskaitīšanas un piešķiršanas darbība, p\arformēta no a=a+s tikai īsākā un vispārpieņemtā formā
//saskaitīšanas un piešķiršanas darbībās prioritāra ir saskaitīšana, piešķiršana ir otra prioritāte
//Tātad sākotnēji tiks veikta saskaitīšana, un rezultāts pārrakstīs esošo a vērtību ar jauno  vērtību
//Datu tips saglabāsies
printf("Pēc cikla: a= %.20f (ar peldošo %e)\n",a,a);
}

return 0;
}
