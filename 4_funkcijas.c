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

int c_in_a=0;
int c_in_b=0;
int q_in_2=0;


double saaksim (int num_1, int num2)
{
double c_result=(float)num_1/num2;
//printf("Haiduk no ceturtās funkcijas kaut ko atgriežam!!!!");
printf("Skaitļu %d un %d dalījums ir %.4f\n",num_1, num2,c_result);
return c_result;
}

void solis (int otra_out)
{
//float in_otra=(float)otra_out/1.0;
printf("No funkcijas ar ievadi bez izvades atgriežam to ko tikko ievadījāt = %d\n",otra_out);//in_otra);
}

int triis()
{
double pi = 22.0/7.0;
printf("No trešās funkcijas atgriežam konstanti pi= %lf\n",pi);
return pi;
}

void beigas()
{
printf("Neko nepiešķiram, neko nemainam, vienkārši no ceturtās funkcijas izvadam kaut kādu sviestu\n");
}

int main()
{
printf("Ievadiet pirmo veselu skaitli:\n");
scanf("%d", &c_in_a);
printf("Ievadiet otro veselu skaitli skaitli:\n");
scanf("%d", &c_in_b);
saaksim(c_in_a, c_in_b);
printf("Ievadiet veselu skaitli, ko atgriezīsim no otrās funkcijas:\n");
scanf("%d", &q_in_2);
solis(q_in_2);
triis();
beigas();

return 0;
}
