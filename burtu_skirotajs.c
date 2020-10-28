#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 20
// Izmantotās saites:
//https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
//https://stackoverflow.com/questions/33294426/sort-string-by-character-in-c-programming
//https://stackoverflow.com/questions/30065675/what-does-scanf-nc-mean

//Pieaugošā šķirošana skaitlim
int numaug (const void * a, const void * b){
if (*(int*)a!=*(int*)b)
return (*(int*)a - *(int*)b);
return 0;
}

//Dilstošā šķirošana skaitlim
int numdilst(const void * a, const void * b){
if (*(int*)b!=*(int*)a)
return (*(int*)b - *(int*)a);
return 0;
}

//Augošā šķirošana char pēc ASCII vērtības
int charaug(const void * a, const void * b){
if (*(char*)a!=*(char*)b)
return (*(char*)a - *(char*)b);
return 0;
}

//Dilstošā šķirošana char pēc ASCII vērtības
int chardilst(const void * a, const void * b){
if (*(char*)b!=*(char*)a)
return (*(char*)b - *(char*)a);
return 0;
}

int n;
int main() {

char first; //Mainīgais skaitļu vai char pārbaudei
printf("Ievadīsiet skaitļus (1) vai burtus(0)? \n");
scanf("%d", &first);

if(first==1)
{
	int numcount;
	printf("Ievadiet cik skaitļus vēlaties sašķirot: \n");
	scanf("%d", &numcount);

	int skaitli[numcount];
	for( n = 0 ; n < numcount; n++ ) {
		printf("Ievadiet %d. pārbaudāmo skaitli: ",n+1);
		scanf("%d", &skaitli[n]);
	}
	int s;
	printf("Secība: 1=augoša, 0=dilstoša: \n");
	scanf("%d",&s);

	printf("Skaitļu virkne pirms kārtošanas: \n");
	for( n = 0 ; n < numcount; n++ ) {
	printf("%d \n", skaitli[n]);
	}



	if(s == 1)
		{
		qsort(skaitli, numcount, sizeof(int), numaug);
		}
	else
		{
		qsort(skaitli, numcount, sizeof(int), numdilst);
		}

	printf("-----------------------------------------------------\n");
	printf("\nSkaitļu virkne pēc kārtošanas: \n");
	for( n = 0 ; n < numcount; n++ ) {
	printf("%d \n", skaitli[n]);
	}
	//return(0);
	}


else
{
	char ievade[MAXS] = {0};
	char izvade[MAXS] = {0};

	printf("Ievadiet šķirojamo burtu kopu, bez dublikātiem: \n"); //Saņemam burtu kopu standarta ievadē
	scanf("%c",&ievade);
	//if (!scanf ("%31[^\n]%*c", ievade)) {
	//printf("Saņemta nepareiza ievade\n\n");
	//return 1;
	}

//strncpy (izvade, ievade, sizeof ievade); //Iekopējam ievadi izvadē pirmš šķirošanas

	int order;
	printf("Kā kārtosim - augoši (1) vai dilstoši: \n");
	scanf("%d", &order);

//strncpy (izvade, ievade, sizeof ievade); //Iekopējam ievadi izvadē pirmš šķirošanas

	if (order==1){
		qsort (izvade,strlen(ievade), sizeof *ievade,charaug);
		}
	else{
		qsort (izvade,strlen(ievade), sizeof *ievade,chardilst);
		}

	printf("\n Ievadītais vārds: %s\n Sašķirotais: %s\n\n",ievade,izvade);

	//return 0;

}	

return 0;
}
