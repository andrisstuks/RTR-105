//Kods dažādu  datu tipu mērīšanai
// Informācijas vienības ar kurām  operē cilvēki - simboli un skaitļi
// Simbli: burti, cipari, punktuācijas zīmes utt- ASCII tabula -simbols vs binārs kods

// skaitļi: veseli skaitļi, reāli skaitļi, kompleksie skaitļi <- satur divas daļas - reāllie skaitļi un imaginārie skaitļi (Re un Im), lai aprakstītu komplekso, vajag 2 reālos skaitļus

//Informācijas vienība ar kuru operē dators - bits (0/1)
//Informācijas vienība ar adresi (datorā) - baits
// 1 byte == 8 biti
// ASCII table - one symboyl == 8bit == 1byte
// unique binary combinations inside one byte = 2**8 == 256
// ASCII tabulā - 256 unikāli simboli, (ASCII tabulas 1.daļā - 128 simbolui)
// C valodā obligāti jānorāda mainīgā data tips - ja skaitlis, tad int, ja teksts tad string??? palabošu

#include<stdio.h>

void main()
{
char a=10; //->šī ir definēšana//char datu tips var tikt izmantots maziem skaitļiem

// 1. darbībā - RAM atmiņā tiek atvēlēta vieta viena char datu tipa mainīgā glabāšanai 
//šī vieta  ir viennozīmīgi saķēdēta ar identifikatoru "a" (bet vietai ir arī adrese
// saskaņā ar char datu tipu, vietas izmērs - 1 baits
////Kā šajā gadījumā izskatījās tas atmiņas apgabals: 0000 0 101 vai 1111 1110 vai 0000 1010
// char a; -> deklarēšana
//2. darbība - vērtības piešķiršana
//a=10; //vērtības piešķiršana
//a-> 0000 1010
printf("Mainīgā a vērtība laikā T1 ir: %d\n",a); //-> %d - Šādā veidā ieliekam kur statiskajā tekstā  būs mainīgā vērtībs
// kad gribam attainot, mums no binārās secības jāinterpretē kā veselu skaitli, un to dara %d
//-> \n -> pārceļ kursoru jaunā rindā
a+=24;
printf("Mainīgā a vērtība (laikā t2) ir: %d\n",a);
//Varam definēt nemainīgu vērtību ar #define
#define pi 3;
printf("Mainīgā a vērtība (laikā t3) ir: %d\n",pi);
//izmantosim nemoniskos nosaukumus - kur nosaukumam ir jēga
char mans_mainigais=143;
printf("Mainīgā a vērtība (laikā t4) ir: %d\n",mans_mainigais);
a=0X10;
printf("Mainīgā a vērtība (laikā t5) ir: %d\n",a);//->16
printf("Mainīgā a vērtība (laikā t6) ir: %x\n",a);//->10
printf("Mainīgā a vērtība (laikā t7) ir: 0X%x\n",a);//->0X10
printf("Mainīgā a vērtība (laikā t8) ir: %o (oct)\n",a);//->20

a=65;
printf("Mainīgā a vērtība (laikā t9) ir: %d\n",a);
printf("Mainīgā a vērtība (laikā t10) ir: %x\n",a);
printf("Mainīgā a vērtība (laikā t11) ir: 0X%x\n",a);
printf("Mainīgā a vērtība (laikā t12) ir: %o (oct)\n",a);
printf("Mainīgā a vērtība (laikā t13) ir: %c\n",a);


a='k';
printf("Mainīgā a vērtība (laikā t14) ir: %d\n",a);
printf("Mainīgā a vērtība (laikā t15) ir: %x\n",a);
printf("Mainīgā a vērtība (laikā t16) ir: 0X%x\n",a);
printf("Mainīgā a vērtība (laikā t17) ir: %o (oct)\n",a);
printf("Mainīgā a vērtība (laikā t18) ir: %c\n",a);



//1byte -> 256num
//without sign  -> 0 .... 255
// with sign -> -128 ... 0 .... 127


//Ir vēl citi datu tipi
//int - 
//
int c;
printf("int datu tipa mainīgā izmērs baitos: %d\n", sizeof(c));
//int atbilst 4 baiti (32biti)
//bez zīmes => 0 .... (2^32)-1 jo pirmais skaitlis ir nulle
//ar zīmēm => -(2^31) .... 0 .... (2^31)-1


//-----------------------------
//reālie skaitļi
float tau = 3.14;

printf("Mainīgā a vērtība (laikā t19) ir: %f\n",tau);// iedos noklusētās  6 zīmes aiz komata
printf("Mainīgā a vērtība (laikā t1) ir: %2.f\n",tau);//iedos tikai 2 zīmes aiz komata

}

