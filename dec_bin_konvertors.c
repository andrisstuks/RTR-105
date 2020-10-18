//Skaitļu konvertors - decimālais uz bināro, dec>bin
//Autors: Andris Stuks


#include<stdio.h>

void main()
{
  char bit_place = 0; // bita vietas skaitītājs result. 
  unsigned char input; //Uz šo no ievades novadīsim ievadīto skaitli ar pointeri
  char result[] = "xxxxxxxx"; // Šeit veicot AND salīdzināšanu ierakstīsim decimālskaitlim atbilstošo bitu vērtību

  printf("Lūdzu ievadiet decimālskaitli, mazāku par 256: ");//Decimālajam skaitlim jābūt <=255
  scanf("%hhd", &input); //%hhd apzīmē short short integer or unsigned short short integer, & ir pointeris uz unsigned char mainīgo  input

  for(unsigned char a = 128;a>0;a=a>>1) //vienlaikus definējam un piešķiram vērtību a=128 (bin 1000 0000) , katrā iterācijā pārbaudam vai tas ir lielāks par 0,a=a>>1 - pārbīdam bitus pa labi 
  {					//iegūstot nākamo bitu vērtību  a=64 (bin 0100 0000) un tā līdz galam
    if((a & input) != 0){             // kā nodarbībā - pārbaudam ar AND darbību a un ievades bitus - 1 vai 0 
 
     result[bit_place] = '1'; 		//Ar IF statement - ja bits ir 1, iekš result nomainam atiecīgo bita reģistru

  }else
    {
     result[bit_place] = '0'; 		// To pašu ar nulli
    }
  bit_place++;  //mainam bitu vietas skaitītāju - pieskaitam +1
  }
 printf("Šis skaitlis binārajā sitēmā ir: %s\n", result); //izdrukā rezultātu
}

// Mainot char uz int, varētu konvertēt arī 16 bit skaitļus, t.i <=65535
