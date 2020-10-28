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

void p_funkcija();
int o_funkcija ();
void t_funkcija(int t_in_arg);
double c_funkcija (int c_in_arg_a, float c_in_arg_b);

int main()
{
p_funkcija(); //Izsaucam iepriekš deklarēto un definēto funkciju
o_funkcija();
t_funkcija(o_funkcija());
c_funkcija(o_funkcija(),0.445);
int o_main=o_funkcija();
printf("Šis ir mainīgā izvades pārtvērums jaunā mainīgajā no otrās funkcijas = %d\n",o_main);
printf("Attēlojam to pašu rezultātu, tikai iekļaujot atgriezto, apejot piešķiršanu jaunam mainīgajam= %d\n",o_funkcija());
printf("No main mēs iekapājām arī trešo funct, un cipars ir %d\n",o_funkcija());
double out_is=c_funkcija(o_main,0.113211);
printf("No ceturtās iekapājot sanāk šādi rezultāts %f\n",out_is);
printf("uzrullē nāsis, šī ir izdruka no pamatfunkcijas\n");
return 0;
}

void p_funkcija()
{
printf("Uzvelc slidas, šī ir pirmā funkcijas izdruka\n");
}

int o_funkcija()
{
int a_2=10;

printf("Te ir cipars %d ko atgriest, šī ir otrā funkcijas izdruka no pašas funkcijas\n",a_2);
a_2+=1;
return a_2;
}

void t_funkcija(int t_in_arg)
{
printf("Trešajā funkcijā jau kaut ko atgriežam!!!!");

printf("Trešajā funkcijā esi ievadījis %d, un jā bet ko kā\n",t_in_arg);
}

double c_funkcija (int c_in_arg_a,float c_in_arg_b)
{
double c_result=c_in_arg_a/c_in_arg_b;
printf("Haiduk no ceturtās funkcijas kaut ko atgriežam!!!!");
printf("Dalam %f ar %f un iegūstam %f, zin vai!",c_in_arg_a, c_in_arg_b,c_result);
return c_result;
}
