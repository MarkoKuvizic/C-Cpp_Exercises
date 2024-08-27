#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define DUZINALISTICA 7
#define LISTIC1 "Unesite brojeve u listic"
#define LISTIC2 "Pregledajte listic"
#define BUBANJ "Pregledajte bubanj"
#define UPLATA "Unesite iznos uplate"
#define ISPIS "Ispisi vrednosti"
#define KRAJ "Zavrsite igru"
int listic[DUZINALISTICA], bubanjNiz[DUZINALISTICA], i;
int bubanj(){
    srand(time (0));
    for(i=0; i<DUZINALISTICA; ++i){
            bubanjNiz[i]=rand()%38+1;
            printf("%i", bubanj(i));
    }
    return 0;
    }
void meni()
{
    printf("------------ LOTO ------------\n\n\n1.%s\n2.%s\n3.%s\n4.%s\n5.%s\n0.%s", LISTIC1, LISTIC2, BUBANJ, UPLATA,ISPIS, KRAJ);
    }
void zaokruziBrojeve()
{
    printf("Unos listica:\n\n");
    for(i=0; i<DUZINALISTICA; ++i){

        neValidanUnos:
        printf("Unesite %i. broj>", i+1);
        scanf("%i", &listic[i]);
        if(listic[i]<0 || listic[i]>38)
            {
                printf("Unos nije validan\n\n");
                goto neValidanUnos;
            }
    }
}

int main()
{
    int unos, uplata, osvojeno, pogodjeno=0;

    meni();
    printf("\n>");
    scanf("%i", &unos);
    while(unos!=0){
        switch (unos){
        case 1: zaokruziBrojeve();
        case 2: for(i=0; i<DUZINALISTICA; ++i){
                printf("%i", listic[i]);
        case 3: bubanj();
        case 4: printf("\nUnesite iznos uplate> ");
                scanf("%i", &uplata);
        case 5: for(i=0; i<DUZINALISTICA; ++i){
                    printf("bubanj: %i", bubanj(i));}
    }           for(i=0; i<DUZINALISTICA; ++i){
                printf("listic: %i", listic[i]);}
        }
}
    for(i=0; i<DUZINALISTICA;++i){
        if(bubanj(i)==listic[i]){
            ++pogodjeno;
        }
    }

    osvojeno=uplata*pogodjeno;
    printf("\n\n----------OSVOJILI STE %i dinara----------", osvojeno);
    return 0;

    }


