#include <stdio.h>

#define N 4

int main(){
char rinda1[N]="abcd";// šim masīvam 0-a, 1-b, 2-c, 3-d, bet kompilators beigās ieleik papildus rindas beigu pazīmi - 4.-\0 .Jāņem 'verā, ka ja rindas garums ir 4, tad var rakstīt tikai 3 zīmes, atstājot 4to  rindas beigu simbolam
//Ja tā nedara, rinda var kropļot datus citos reģistros
char rinda2[]={'d','e','f'};//Šādā veidā norādītam masīvam papildus adreses vēlāk netiek iedalītas un tas paliek 3 simbolu liels
char rinda3[]="ghijk";//Ja inicializē simbolu rindu šādi - papildus simbolas ir kompilatora ieliktā rindas beigu pazīme, tātad norādot 5 elemenus aizņems 6 adreses
char *rinda4="lmnop";//Šāds masīvs piesaka masīvu adresēm

printf("1.simbolu rindas izmērs baitos: %lu un simbolos\elementos: %lu\n",sizeof(rinda1),sizeof(rinda1)/sizeof(char));
printf("2.simbolu rindas izmērs baitos: %lu un simbolos\elementos: %lu\n",sizeof(rinda2),sizeof(rinda2)/sizeof(char));
printf("3.simbolu rindas izmērs baitos: %lu un simbolos\elementos: %lu\n",sizeof(rinda3),sizeof(rinda3)/sizeof(char));
printf("4.simbolu rindas izmērs baitos: %lu un simbolos\elementos: %lu\n\n",sizeof(rinda4),sizeof(rinda4)/sizeof(char)); //masīva izmēru veido pointera adreses izmērs, un šeit izmērs - 0t\a elementa adreses izmērs
//32bit sistēmā adreses izmērs - 32 biti jeb 4 baiti, 64bitu sistēmā - 64biti jeb 8baiti
//Šāda izmēra masīva izmēru parādīs šādi. Simbola rindas garumu nosaka šādi
//printf("4.simbolu rindas izmērs baitos: %lu un simbolos\elementos: %lu\n\n",sizeof(rinda4),sizeof(rinda4)/sizeof(char))
char *dmain=rinda4;
int gmain=0, i=0;
while (*dmain != '\0')
{
gmain++;
printf("4.rindas elementa %d. dec kods un simbols: %d (%c)\n",i,*dmain,*dmain);
dmain+=1;
i++;
}
gmain+=1;
printf("ceturtās rindas izmērs baitos ir %lu un simbolos(elementos): %d\n",gmain*sizeof(char),gmain);
printf("\n\n");



for(int i=0;i<N;i++)
{
printf("rinda1: %d. simbola dec kods %d\n",i,rinda1[i]);// var arī *(rinda1+i)
}
printf("\n\n");

for(int i=0;i<3;i++)
{
printf("rinda2: %d. simbola dec kods %d\n",i,rinda2[i]);// var arī *(rinda1+i)
}
printf("\n\n");


for(int i=0;i<6;i++)
{
printf("rinda3: %d. simbola dec kods %d\n",i,rinda3[i]);// var arī *(rinda1+i)
}
printf("\n\n");


for(int i=0;i<8;i++)
{
printf("rinda4: %d. simbola dec kods %d\n",i,rinda4[i]);// var arī *(rinda1+i)
printf("rinda4: %d. simbola adrese %p\n",i,rinda4[i]);// var arī *(rinda1+i)
}
printf("\n\n");



return 0;
}

