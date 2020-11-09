# include <stdio.h>

#define N 5 //cenšamies definēt array lielumu atsevišķi, nevis pa tiešo

int main()
{

int array_a[N];//Tikai izdalīts atmiņas apgabals, un izsaucot parāda to, kas tur ir arī vēsturiski. Deklarējot un piešķirot labāk norādīt array_a[N]={0} lai nodzēstu/pārrakstītu esošās vērtības
int array_b[]={1,2,3};
int array_c[N]={4,5,6};//kad masīvu deklarē array_c[N]={0} tad ja pieprasa neaizpildītos elementus (jo N=5 un ir iedalītas 5 adreses) atgriež vērtību 0
int array_d[3][2]={{1,2},{3,4},{5,6}}; //Pirmais norāda cik elementi, otrais - cik apakšelementi, kas te arī izpildās - 3 elementi ar 2 apakšelementiem katrā, tātad 3 rindas ar 2 kolonnām



printf("a masīva izmērs baitos: %lu un elementos %lu\n",sizeof(array_a), sizeof(array_a)/sizeof(int));
printf("b masīva izmērs baitos: %lu un elementos %lu\n",sizeof(array_b), sizeof(array_b)/sizeof(int));
printf("c masīva izmērs baitos: %lu un elementos %lu\n",sizeof(array_c), sizeof(array_c)/sizeof(int));
printf("d masīva izmērs baitos: %lu un elementos %lu\n\n",sizeof(array_d), sizeof(array_d)/sizeof(int));

//

printf("b masīva adrese -%p\n", array_b);
printf("b masīva pirmā (0.) elementa vērtība: %d\n",*array_b);
printf("b masīva pirmā (0.) elementa adrese: %p\n",&array_b[0]);
printf("b masīva pirmā (0.) elementa vērtība: %d\n\n\n",array_b[0]);

printf("b masīva otrā (1.) elementa adrese: %p\n",&array_b[1]);
printf("b masīva otrā (1.) elementa vērtība: %d\n",array_b[1]);
printf("b masīva otrā (1.) elementa adrese: %p\n",array_b+1);
printf("b masīva otrā (1.) elementa vērtība: %d\n\n\n",*(array_b+1));


printf("c masīva adrese -%p\n", array_c);
printf("c masīva pirmā (0.) elementa vērtība: %d\n",*array_c);
printf("c masīva pirmā (0.) elementa adrese: %p\n",&array_c[0]);
printf("c masīva pirmā (0.) elementa vērtība: %d\n\n\n",array_c[0]);

printf("d masīva adrese -%p\n\n", array_d);//tā patiesībā ir masīva sākuma adrese

printf("d masīva pirmā elementa pirmā apakšelementa (0.0) elementa adrese: %p\n",&array_d[0][0]);
printf("d masīva pirmā elementa otrā apakšelementa (0.1) elementa adrese: %p\n",&array_d[0][1]);
printf("d masīva otrā elementa pirmā apakšelementa (1.0) elementa adrese: %p\n",&array_d[1][0]);
printf("d masīva otrā elementa otrā apakšelementa (1.1) elementa adrese: %p\n",&array_d[1][1]);
printf("d masīva trešā elementa pirmā apakšelementa (2.0) elementa adrese: %p\n",&array_d[2][0]);
printf("d masīva trešā elementa otrā apakšelementa (2.1) elementa adrese: %p\n\n",&array_d[2][1]);

printf("d masīva otrā elementa otrā apakšelementa (1.1) elementa vērtība: %d\n",*(array_d[1]+1));
printf("d masīva ? elementa ? apakšelementa (?.?) elementa vērtība: %d\n",*(array_d[2]+1)); //iterēt var ar +1
printf("d masīva otrā elementa otrā apakšelementa (2.1) elementa vērtība: %d\n\n\n",array_d[2][1]);//vai norādot precīzu adresi
printf("d masīva otrā elementa otrā apakšelementa (1.1) elementa vērtība: %d\n",*(array_d[1]+1));


return 0;

}
