#include<iostream> 

using namespace std; 

//definiranje na funkicja 

void merge(int *a, int pocetok, int kraj, int polovina) 

{ 

    int i, j, k, c[50]; 

    i = pocetok; 

    k = pocetok; 

    j = polovina + 1; 

    while (i <= polovina && j <= kraj) { 

        if (a[i] < a[j]) { 

            c[k] = a[i]; 

            k++; 

            i++; 

        } 

        else  { 

            c[k] = a[j]; 

            k++; 

            j++; 

        } 

    } 

    while (i <= polovina) { 

        c[k] = a[i]; 

        k++; 

        i++; 

    } 

    while (j <= kraj) { 

        c[k] = a[j]; 

        k++; 

        j++; 

    } 

    for (i = pocetok; i < k; i++)  { 

        a[i] = c[i]; 

    } 

} 

//definiranje na funkicja  

void merge_sort(int *a, int pocetok, int kraj) 

{ 

    int polovina; 

    if (pocetok < kraj){ 

        polovina=(pocetok+kraj)/2; 

        merge_sort(a,pocetok,polovina); 

        merge_sort(a,polovina+1,kraj); 

        merge(a,pocetok,kraj,polovina); 

    } 

} 

//glavna programa  

int main() 

{ 

//deklracija na pokazuvac kon datoteka  

FILE *pok; 

char text[1000],c; 

int k=0,a[1000]; 

//postapka za otvoranje na datoteka za citanje na podatoci 

pok=fopen("proekt01INKI708.txt","r"); 

//citanje od datoteka 

while((c=fgetc(pok))!=EOF) 

{ 

text[k]=c; 

k++; 

} 

//pecatenje na text od datoteka 

cout<<"\n Tekst od datoteka :"; 

cout<<"\n ========================================================"<<endl; 

cout<<"  "; 

for(int i=0;i<k;i++) 

cout<<text[i]; 

//konvertiranje na text vo int ASCII 

cout<<"  "; 

for(int i=0;i<k;i++) 

a[i]=(int)text[i]; 

cout<<endl; 

cout<<"\n ASCII kodovi na tekstot od datoteka : "; 

cout<<"\n ========================================================"<<endl; 

cout<<"  "; 

for(int i=0;i<k;i++) 

cout<<a[i]<<"  "; 

//povik na funkcija 

    merge_sort(a,0,k-1); 

//pecatenje na int sortirani vrendosti ASCII 

cout<<endl; 

cout<<"\n ASCII odovi na tekstot od datoteka sortirani : "; 

cout<<"\n ========================================================"<<endl; 

cout<<"  "; 

for(int i=0;i<k;i++) 

cout<<a[i]<<"  "; 

cout<<endl; 

cout<<"\n Int Ascii kodovi se dekodirani bo karakteri i sortirani : "; 

cout<<"\n ========================================================"<<endl; 

cout<<"  "; 

for(int i=0;i<k;i++) 

cout<<(char)a[i]; 

return 0; 

} 
