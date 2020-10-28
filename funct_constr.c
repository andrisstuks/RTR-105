// Lietotāja funkcija - aprakstam vienu reizi, varam izmantot vairākas reizes
// Princips tāpat kā def func_name(): iekš Python
// C gadījumā 
//data_type vērtība 
//func_name(argumenti)
//{
//darbības; 
//atgriešana ar return vērtība;}
// Principa līdzīgi kā main funkcijai
//Funkcija var būt bez argumentiem
// ja funkcija ir bez argumentiem, tad atgriežamais datu tips ir -> void
// 1. funkcija bez argumentiem un bez atgriežamiem lielumiem
// 2. funkcija bez argumentiem ar atgriežamiem lielumiem
// 3. ar argumentiem bez atgriežamiem lielumiem
// 4. funkcija saņem argumentus un atdod vērtību
//
//Funkciju jādeklarē un jādefinē pirms izmantošanas, to var deklarēt pirms main un definēt to vēlāk 
// Labāk darīt visu kopā


# include <stdio.h>

void p_funkcija()
{
printf("Uzvelc slidas, šī ir pirmā funkcijas izdruka\n");
}


int main()
{
p_funkcija; //Izsaucam iepriekš deklarēto un definēto funkciju
printf("uzrullē nāsis, šī ir izdruka no pamatfunkcijas\n");
return 0;
}



