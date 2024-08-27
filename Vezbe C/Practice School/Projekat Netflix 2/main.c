#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NOVIFILM "1. Unesi Novi Film"
#define ISPISFILM "2. Ispis Svih Filmova"
#define PRETRAGA "3. Pretrazi Sve Filmove"
#define IZMENA "4. Izmeni Film"
#define BRISANJE "5. Obrisi Film"
#define OCENA "6. Oceni Film"
#define PREPORUKA "7. Preporuci Film"




struct dt {

    int dd;
    int mm;
    int yy;

};

struct dtg {

    int dd;
    int mm;
    int yy;

};

struct Film {
    char naziv[20];
    int id;
    char imeRezisera[20];
    int duzinaTrajanja;
    double prosecnaOcena;
    char zanr[20];
    struct dt Datum;
    int brojOcena;
    char Glumci[5][20];
    struct dtg datumGlumci[5];

};

struct Film Filmovi[50];

struct dFilm {
    char naziv[20];
    int id;
    char imeRezisera[20];
    int duzinaTrajanja;
    double prosecnaOcena;
    char zanr[20];
    struct dt Datum;
    int brojOcena;
    char Glumci[5][20];
    struct dtg datumGlumci[5];

};
typedef struct dFilm dinamickiFilm;

struct dinamickiNiz{

    int filled;
    int cap;
    dinamickiFilm *parray;

};

typedef struct dinamickiNiz Niz;

//pomocna f-ja za inicijalizaciju dinamickog niza struktura

void init_array(Niz *p){

    p->parray = NULL;
    p->cap = 0;
    p->filled = 0;

}

//pomocna f-ja za povecavanje kapaciteta dinamickog niza struktura

void resize_array(Niz *p){

    if(p->parray == NULL){
        p->cap = 1;
    }else{p->cap += 1;}

    p->parray = (dinamickiFilm *)realloc(p->parray, p->cap * sizeof(dinamickiFilm));

}

int NoviFIlm(FILE* f, int id, Niz *pNiz){

    char naziv[50], imeRezisera[20], zanr[20], datum[20], imeGlumca[5][50], strOcena[50], strBrojOcena[10], strDuzinaTrajanja[20];
    char* pNaziv;
    char** pZanr;
    char** pDatum;
    char* pImeGlumca[5];
    char* pReziser;
    char tempDatumGlumci[20];

    int* pBrojOcena;
    int duzinaTrajanja, brojOcena, i, j;
    int* pDuzinaTrajanja;

    double  prosecnaOcena;
    double* pProsecnaOcena;

    fputs("\n\n------------------------------------------------\n\n\n", f);
    printf("\n-------------UNOS NOVOG FILMA-------------\n\n\n");
    printf("UPOZORENJE: Umesto Razmaka koristiti _\n\n");
    printf("Unesite Naziv Filma:\n\n");
    printf(">");

    if(pNiz->filled == pNiz->cap){resize_array(pNiz);}

    //Unos naziva filma
    scanf("%s", &Filmovi[id].naziv);

    strcpy(pNiz->parray[pNiz->filled].naziv, Filmovi[id].naziv);
    //printf("Naziv Je: %s", pNiz->parray[pNiz->filled].naziv);
    //pNaziv = Filmovi[id].naziv ;
    //*pNaziv = naziv;
    //fputs("Naziv:", f);
    fputs("Naziv:", f);
    fputs(Filmovi[id].naziv, f);

    //Unos imena rezisera
    printf("\n\nUnesite ime rezisera:\n\n>");
    scanf(" %s", &Filmovi[id].imeRezisera);

    strcpy(pNiz->parray[pNiz->filled].imeRezisera, Filmovi[id].imeRezisera);
    //printf("Ime Rezisera Je: %s", pNiz->parray[pNiz->filled].imeRezisera);
    //pReziser = Filmovi[id].imeRezisera;
    //*pReziser = imeRezisera;
    fputs("\n\nIme Rezisera:  ", f);
    fputs(Filmovi[id].imeRezisera, f);

    //Unos zanra filma
    printf("\n\nUnesite Zanr Filma:\n\n>");
    scanf(" %s", &Filmovi[id].zanr);
    //pZanr = Filmovi[id].zanr;
    //*pZanr = zanr;
    strcpy(pNiz->parray[pNiz->filled].zanr, Filmovi[id].zanr);
    //printf("Zanr Je: %s", pNiz->parray[pNiz->filled].zanr);

    fputs("\n\nZanr: ", f );
    fputs(Filmovi[id].zanr, f);

    //Unos datuma izlaska filma
    dat:
    printf("\n\nUnesite datum kada je film izasao:\n\n>");
    scanf(" %s", &datum);

    Filmovi[id].Datum.dd = (datum[0] - '0')*10 + datum[1] - '0';
    Filmovi[id].Datum.mm = (datum [3] - '0')*10 + datum[4] - '0';
    Filmovi[id].Datum.yy = (datum [6] - '0')*1000 + (datum[7] - '0')*100 + (datum [8] - '0')*10 + datum [9] - '0';

    pNiz->parray[pNiz->filled].Datum.dd = Filmovi[id].Datum.dd;
    pNiz->parray[pNiz->filled].Datum.mm = Filmovi[id].Datum.mm;
    pNiz->parray[pNiz->filled].Datum.yy = Filmovi[id].Datum.yy;

    //printf("Datum je %i.%i.%i. ", pNiz->parray[pNiz->filled].Datum.dd, pNiz->parray[pNiz->filled].Datum.mm, pNiz->parray[pNiz->filled].Datum.yy);
    //pDatum = Filmovi[id].Datum;
    //*pDatum = datum;

    if(Filmovi[id].Datum.dd > 31){

        printf("\nNije Validan Datum\n");
        goto dat;

    }else if(Filmovi[id].Datum.mm > 12){

        printf("\nNije Validan Datum\n");
        goto dat;

    }else if(Filmovi[id].Datum.yy > 2018 || Filmovi[id].Datum.yy < 1900){

        printf("\nNije Validan Datum\n");
        goto dat;

    }else if((Filmovi[id].Datum.mm  == 4 || Filmovi[id].Datum.mm == 6 || Filmovi[id].Datum.mm == 9 || Filmovi[id].Datum.mm == 11) && Filmovi[id].Datum.dd > 30){

        printf("\nNije Validan Datum\n");
        goto dat;

    }else if (Filmovi[id].Datum.mm  == 2 && Filmovi[id].Datum.dd  > 28){

        printf("\nNije Validan Datum\n");
        goto dat;

    }

    fputs("\n\nDatum: ", f);
    fputs(datum, f);

    fflush(stdin);

    //Unos Glumaca
    printf("\n\n");

    for(i=0; i<5; ++i){

        printf("Unesite Ime %i. Glumca:\n\n", i+1);
        scanf(" %s", &Filmovi[id].Glumci[i]);
        fputs("\n\nIme Glumca: ", f);
        fputs(Filmovi[id].Glumci[i], f);

        strcpy(pNiz->parray[pNiz->filled].Glumci[i], Filmovi[id].Glumci[i]);
        //printf("%i. Glumac je: %s\n", i+1, pNiz->parray[pNiz->filled].Glumci[i]);

        dat2 :

        printf("Unesite Datum Rodjenja %i. Glumca:\n\n", i+1);
        scanf(" %s", &tempDatumGlumci);
        Filmovi[id].datumGlumci[i].dd = (tempDatumGlumci[0] - '0')*10 + tempDatumGlumci[1] - '0';
        Filmovi[id].datumGlumci[i].mm = (tempDatumGlumci[3] - '0')*10 + tempDatumGlumci[4] - '0';
        Filmovi[id].datumGlumci[i].yy = (tempDatumGlumci[6] - '0')*1000 + (tempDatumGlumci[7] - '0')*100 + (tempDatumGlumci[8] - '0')*10 + tempDatumGlumci[9] - '0';

        pNiz->parray[pNiz->filled].datumGlumci[i].dd = Filmovi[id].datumGlumci[i].dd;
        pNiz->parray[pNiz->filled].datumGlumci[i].mm = Filmovi[id].datumGlumci[i].mm;
        pNiz->parray[pNiz->filled].datumGlumci[i].yy = Filmovi[id].datumGlumci[i].yy;

        //printf("Rodjen je: %i.%i.%i.\n", pNiz->parray[pNiz->filled].datumGlumci[i].dd, pNiz->parray[pNiz->filled].datumGlumci[i].mm, pNiz->parray[pNiz->filled].datumGlumci[i].yy);


        if(Filmovi[id].datumGlumci[i].dd > 31){

        printf("\nNije Validan Datum\n");
        goto dat2;

    }else if(Filmovi[id].datumGlumci[i].mm > 12){

        printf("\nNije Validan Datum\n");
        goto dat2;

    }else if(Filmovi[id].datumGlumci[i].yy > 2018 || Filmovi[id].datumGlumci[i].yy < 1900){

        printf("\nNije Validan Datum\n");
        goto dat2;

    }else if((Filmovi[id].datumGlumci[i].mm  == 4 || Filmovi[id].datumGlumci[i].mm == 6 || Filmovi[id].datumGlumci[i].mm == 9 || Filmovi[id].datumGlumci[i].mm == 11) && Filmovi[id].datumGlumci[i].dd > 30){

        printf("\nNije Validan Datum\n");
        goto dat2;

    }else if (Filmovi[id].datumGlumci[i].mm  == 2 && Filmovi[id].datumGlumci[i].dd  > 28){

        printf("\nNije Validan Datum\n");
        goto dat2;

    }

        fputs(" Datum Rodjenja: ", f);
        fputs(tempDatumGlumci, f);
    }

    //Unos ocene
    printf("\n\nUnesite prosecnu ocenu:\n\n> ");
    scanf(" %lf", &prosecnaOcena);
    pProsecnaOcena = &(Filmovi[id].prosecnaOcena);
    *pProsecnaOcena = prosecnaOcena;

    pNiz->parray[pNiz->filled].prosecnaOcena = Filmovi[id].prosecnaOcena;
    //printf("Prosecna Ocena je %lf", pNiz->parray[pNiz->filled].prosecnaOcena);

    snprintf(strOcena, 50, "%f", prosecnaOcena);

    fputs("\n\nProsecna ocena: ", f);
    fputs(strOcena, f);


    //Unos broj ocena
    printf("\n\nUnesite Broj Ocena:\n\n> ");
    scanf(" %i", &brojOcena);
    pBrojOcena = &(Filmovi[id].brojOcena);
    *pBrojOcena = brojOcena;

    pNiz->parray[pNiz->filled].brojOcena = Filmovi[id].brojOcena;
    //printf("Broj Ocena je %i", pNiz->parray[pNiz->filled].brojOcena);

    snprintf(strBrojOcena, 10, "%i", brojOcena);

    fputs("\n\nBroj Ocena: ", f);
    fputs(strBrojOcena, f);


    //Unos duzine trajanja filma
    printf("\n\nUnesite Duzinu Trajanja:\n\n> ");
    scanf(" %i", &duzinaTrajanja);
    pDuzinaTrajanja = &(Filmovi[id].duzinaTrajanja);
    *pDuzinaTrajanja = duzinaTrajanja;

    pNiz->parray[pNiz->filled].duzinaTrajanja = Filmovi[id].duzinaTrajanja;
    //printf("Duzina Trajanja: %i", pNiz->parray[pNiz->filled].duzinaTrajanja);


    snprintf(strDuzinaTrajanja, 20, "%i", duzinaTrajanja);

    fputs("\n\nDuzina Trajanja: ", f);
    fputs(strDuzinaTrajanja, f);



    pNiz->filled++;
    ++id;
    return id;
}

void ispisSvihFilmova(int id){

    int i = 0, j;

    while(i < id){

        printf("\n\n-----------FILM %i.-----------\n\n", i+1);
        printf("Naziv: %s\n", Filmovi[i].naziv);
        printf("Ime Rezisera: %s\n", Filmovi[i].imeRezisera);
        printf("Zanr: %s\n", Filmovi[i].zanr);
        printf("Datum: %i.%i.%i.\n", Filmovi[i].Datum.dd, Filmovi[i].Datum.mm, Filmovi[i].Datum.yy );

        for(j = 0; j < 5; j++){


            printf("\nGlumac broj %i: %s", j+1, Filmovi[i].Glumci[j]);
            printf(" || Datum Rodjenja: %i.%i.%i.", Filmovi[i].datumGlumci[j].dd, Filmovi[i].datumGlumci[j].mm, Filmovi[i].datumGlumci[j].yy);

        }

        printf("\nProsecna Ocena: %lf\n", Filmovi[i].prosecnaOcena);
        printf("Broj Ocena: %i\n", Filmovi[i].brojOcena);
        printf("Duzina trajanja: %i\n", Filmovi[i].duzinaTrajanja);

        ++i;
    }




}

int ucitajFilmove(FILE* f){

    int i = 0, j = 0, id;
    char tempProsecnaOcena[10], tempBrojOcena, tempTrajanje[3], tempDatum[10], tempDatumGlumac[20];

    fseek(f, 63, SEEK_SET);

    for(id = 0; fgetc(f) != EOF; id++ ){

    if(id > 0){fseek(f, 62, SEEK_CUR);}

    fgets(Filmovi[id].naziv, 20, f);
    //printf("%s", Filmovi[id].naziv);

    fseek(f, 17, SEEK_CUR);

    fgets(Filmovi[id].imeRezisera, 20, f);
    //printf("%s", Filmovi[id].imeRezisera);

    fseek(f, 8, SEEK_CUR);

    fgets(Filmovi[id].zanr, 20, f);
    //printf("%s", Filmovi[id].zanr);

    fseek(f, 9, SEEK_CUR);

    fgets(tempDatum, 20, f);
    Filmovi[id].Datum.dd = (tempDatum[0] - '0')*10 + tempDatum[1] - '0';
    Filmovi[id].Datum.mm = (tempDatum [3] - '0')*10 + tempDatum[4] - '0';
    Filmovi[id].Datum.yy = (tempDatum [6] - '0')*1000 + (tempDatum[7] - '0')*100 + (tempDatum[8] - '0')*10 + tempDatum[9] - '0';
    //printf("%i.%i.%i.", Filmovi[id].Datum.dd, Filmovi[id].Datum.mm, Filmovi[id].Datum.yy);

    j = 0;

    while(j < 5){
        fseek(f, 14, SEEK_CUR);
        if(j>0){fseek(f, 2, SEEK_CUR);}
        fscanf(f, " %s" , Filmovi[id].Glumci[j]);
        //printf("\n Ime Glumca: ");
        //printf("DEBUG2 %s DEBUG2", Filmovi[id].Glumci[j]);
        //printf("%s", Filmovi[id].Glumci[j]);
        fseek(f, 17, SEEK_CUR);
        //if(j>0){ fseek(f, 3, SEEK_CUR);}
        fscanf(f, " %s", tempDatumGlumac);
        //printf("DEBUG %s DEBUG", tempDatumGlumac);
        Filmovi[id].datumGlumci[j].dd = (tempDatumGlumac[0] - '0')*10 + tempDatumGlumac[1] - '0';
        Filmovi[id].datumGlumci[j].mm = (tempDatumGlumac[3] - '0')*10 + tempDatumGlumac[4] - '0';
        Filmovi[id].datumGlumci[j].yy = (tempDatumGlumac[6] - '0')*1000 + (tempDatumGlumac[7] - '0')*100 + (tempDatumGlumac[8] - '0')*10 + tempDatumGlumac[9] - '0';
       //printf(" %i.%i.%i.", Filmovi[id].datumGlumci[j].dd, Filmovi[id].datumGlumci[j].mm, Filmovi[id].datumGlumci[j].yy);

        j++;

    }

    fseek(f, 19, SEEK_CUR);

    fgets(tempProsecnaOcena, 10, f);

    Filmovi[id].prosecnaOcena = atof(tempProsecnaOcena);
    //printf("\n%lf", Filmovi[id].prosecnaOcena);

    fseek(f, 16, SEEK_CUR);
    fflush(f);
    fflush(stdin);
    tempBrojOcena = fgetc(f);
    Filmovi[id].brojOcena = (int)tempBrojOcena - 48;
    //printf("\nbroj ocena %i ", Filmovi[id].brojOcena);

    fseek(f, 21, SEEK_CUR);
    fgets(tempTrajanje, 4, f);
    Filmovi[id].duzinaTrajanja = atoi(tempTrajanje);
    //printf("\nDuzina %i ",Filmovi[id].duzinaTrajanja );


}return id;}

void search(int id){

    int i = 0, j = 0, x;
    char naz[50];
    printf("\n Pretrazite po nazivu, koristite _ kao space\n>");
    scanf("%s", &naz);

    while (i < id){

        for(x=0;Filmovi[i].naziv[x]!=NULL;x++){
            if(Filmovi[i].naziv[x] == '\n'){
                Filmovi[i].naziv[x] = NULL;
            }

        }

        if(strcmp(Filmovi[i].naziv, naz) == 0){

        printf("Naziv: %s\n", Filmovi[i].naziv);
        printf("Ime Rezisera: %s\n", Filmovi[i].imeRezisera);
        printf("Zanr: %s\n", Filmovi[i].zanr);
        printf("Datum: %i.%i.%i.\n", Filmovi[i].Datum.dd, Filmovi[i].Datum.mm, Filmovi[i].Datum.yy );

        for(j = 0; j < 5; j++){


            printf("\nGlumac broj %i: %s", j+1, Filmovi[i].Glumci[j]);
            printf(" || Datum Rodjenja: %i.%i.%i.", Filmovi[i].datumGlumci[j].dd, Filmovi[i].datumGlumci[j].mm, Filmovi[i].datumGlumci[j].yy);

        }

        printf("\nProsecna Ocena: %lf\n", Filmovi[i].prosecnaOcena);
        printf("Broj Ocena: %i\n", Filmovi[i].brojOcena);
        printf("Duzina trajanja: %i\n", Filmovi[i].duzinaTrajanja);

        }

        i++;
    }

}
FILE * izmenaFilma(int id, FILE *f){

    int x, i = 0, j = 0;
    char naz[50], novi[50], str[60], tempDatumGlumci[10], tempGlumci[5][50];
    FILE *p = fopen("Temp.txt", "a+");

    printf("\nSta zelite da promenite?\n");
    printf("\n1. Naziv");
    printf("\n2. Ime Rezisera");
    printf("\n3. Zanr");
    printf("\n4. Datum");
    printf("\n5. Glumce");
    printf("\n\n >");

    scanf("%i", &x);

    fseek(f, 0, SEEK_SET);


    printf("\n\nKoji film (Unesite Naziv, _ u mesto razmaka):");
    printf(">");
    scanf("%s", &naz);



    switch(x){

        case 1:

            printf("\nUnesite Novi Naziv:\n>");
            scanf(" %s", &novi);

            while(fgetc(f) != EOF){

                fseek(f, -1, SEEK_CUR);

                fgets(str, 60, f);



                if(strstr(str, naz) != NULL){
                        snprintf(str, 60, "Naziv:%s\n", novi);
                        strcpy(Filmovi[i].naziv, novi);


                }

                fputs(str, p);
                i++;

            }
            break;
        case 2:

            fseek(f, 0, SEEK_SET);

            printf("\nUnesite Novo Ime Rezisera:\n>");
            scanf(" %s", &novi);

            while(fgetc(f) != EOF){

                fseek(f, -1, SEEK_CUR);

                fgets(str, 60, f);



                if(strstr(str, naz) != NULL){

                        fputs(str, p);

                         while(fgetc(f) != EOF){

                                fseek(f, -1, SEEK_CUR);
                                fgets(str, 60, f);

                                if(strstr(str, "Ime Rezisera:") != NULL){
                        snprintf(str, 60, "Ime Rezisera:  %s\n", novi);
                        strcpy(Filmovi[i].imeRezisera, novi);
                        }

                                fputs(str, p);

                        }

                }else{fputs(str, p);}


                i++;

            }
            break;
        case 3:

            fseek(f, 0, SEEK_SET);

            printf("\nUnesite Novi Zanr:\n>");
            scanf(" %s", &novi);

            while(fgetc(f) != EOF){

                fseek(f, -1, SEEK_CUR);

                fgets(str, 60, f);


                if(strstr(str, naz) != NULL){

                        fputs(str, p);

                         while(fgetc(f) != EOF){

                                fseek(f, -1, SEEK_CUR);
                                fgets(str, 60, f);

                                if(strstr(str, "Zanr:") != NULL){
                        snprintf(str, 60, "Zanr: %s\n", novi);
                        strcpy(Filmovi[i].zanr, novi);
                        }

                                fputs(str, p);

                        }

                }else{fputs(str, p);}


                i++;

            }
        case 4:
            fseek(f, 0, SEEK_SET);

            printf("\nUnesite Novi Datum:\n>");
            scanf(" %s", &novi);

            while(fgetc(f) != EOF){

                fseek(f, -1, SEEK_CUR);

                fgets(str, 60, f);


                if(strstr(str, naz) != NULL){

                        fputs(str, p);

                         while(fgetc(f) != EOF){

                                fseek(f, -1, SEEK_CUR);
                                fgets(str, 60, f);

                                if(strstr(str, "Datum:") != NULL){
                        snprintf(str, 60, "Datum: %s\n", novi);
                        Filmovi[id].Datum.dd = (novi[0] - '0')*10 + novi[1] - '0';
                        Filmovi[id].Datum.mm = (novi [3] - '0')*10 + novi[4] - '0';
                        Filmovi[id].Datum.yy = (novi [6] - '0')*1000 + (novi[7] - '0')*100 + (novi[8] - '0')*10 + novi[9] - '0';

                        }

                                fputs(str, p);

                        }

                }else{fputs(str, p);}


                i++;

    }
        case 5:
            fseek(f, 0, SEEK_SET);
            j = 0;

            while(strstr(str, naz) != NULL){

                fgets(str, 60, f);
                if(strstr(str, "----")!=NULL){j++;}


            }

            fseek(f, 0, SEEK_SET);

            for(i=0; i<5; ++i){

            printf("Unesite Novo Ime %i. Glumca:\n\n", i+1);
            scanf(" %s", &Filmovi[j].Glumci[i]);

            dat2 :

            printf("Unesite Datum Rodjenja %i. Glumca:\n\n", i+1);
            scanf(" %s", &tempDatumGlumci);

            Filmovi[j].datumGlumci[i].dd = (tempDatumGlumci[0] - '0')*10 + tempDatumGlumci[1] - '0';
            Filmovi[j].datumGlumci[i].mm = (tempDatumGlumci[3] - '0')*10 + tempDatumGlumci[4] - '0';
            Filmovi[j].datumGlumci[i].yy = (tempDatumGlumci[6] - '0')*1000 + (tempDatumGlumci[7] - '0')*100 + (tempDatumGlumci[8] - '0')*10 + tempDatumGlumci[9] - '0';

            if(Filmovi[j].datumGlumci[i].dd > 31){

            printf("\nNije Validan Datum\n");
            goto dat2;

        }else if(Filmovi[j].datumGlumci[i].mm > 12){

            printf("\nNije Validan Datum\n");
            goto dat2;

        }else if(Filmovi[j].datumGlumci[i].yy > 2018 || Filmovi[j].datumGlumci[i].yy < 1900){

            printf("\nNije Validan Datum\n");
            goto dat2;

        }else if((Filmovi[j].datumGlumci[i].mm  == 4 || Filmovi[j].datumGlumci[i].mm == 6 || Filmovi[j].datumGlumci[i].mm == 9 || Filmovi[j].datumGlumci[i].mm == 11) && Filmovi[j].datumGlumci[i].dd > 30){

            printf("\nNije Validan Datum\n");
            goto dat2;

        }else if (Filmovi[j].datumGlumci[i].mm  == 2 && Filmovi[j].datumGlumci[i].dd  > 28){

            printf("\nNije Validan Datum\n");
            goto dat2;

        }
        }

            fseek(f, 0, SEEK_SET);
            int s = 0;
            char temp[60];


            while(fgetc(f) != EOF){

                    fseek(f, -1, SEEK_CUR);
                    fgets(str, 60, f);
                    if(strstr(str, naz) != NULL){
                            if(strstr(str,"Ime Glumca:") == NULL){fputs(str, p);
                                                                  fputs("\n", p);}

                while(fgetc(f) != EOF){

                    //fseek(f, -1, SEEK_CUR);
                    fgets(str, 60, f);

                    if(strstr(str, "Ime Glumca:")!=NULL && s == 0){

                        for(i=0;i < 5; i++){
                                s++;

                            //fseek(p, -1, SEEK_CUR);

                            snprintf(str, 60, "Ime Glumca: %s Datum Rodjenja: %i.%i.%i.\n\n", Filmovi[j].Glumci[i], Filmovi[j].datumGlumci[i].dd, Filmovi[j].datumGlumci[i].mm, Filmovi[j].datumGlumci[i].yy);
                            fputs(str, p);
                            //snprintf(str, 60, " Datum Rodjenja: %i.%i.%i.\n\n", Filmovi[j].datumGlumci[i].dd, Filmovi[j].datumGlumci[i].mm, Filmovi[j].datumGlumci[i].yy);
                            //fputs(str, p);


                                    }


                        }else{
                            if(strstr(str, "Ime Glumca:") == NULL){fputs(str, p);
                                                                    fputs("\n", p);}


                            }

    }

            }else{fputs(str, p);}




}}
    fclose(f);
    fclose(p);


    remove("Filmovi.txt");
    rename("Temp.txt","Filmovi.txt");
    remove("Fimovi.txt");

    return p;}
    void preporuci(int id){
        int i = 0, x;
        float max = 0;
        char zanr[60];

        printf("Unesite Zanr: ");
        scanf(" %s", zanr);

        while(i < id){

            if(strstr(Filmovi[i].zanr, zanr)){

            if(Filmovi[i].prosecnaOcena > max){
                    x = i;
                    max = Filmovi[i].prosecnaOcena;
                }
            }
            i++;
        }
    printf("Najbolji film tog zanra je %s", Filmovi[x].naziv);
    }
FILE * obrisi(int id, FILE * f){

    FILE * p = fopen("Temp.txt", "a+");
    char naz[60], str[60];
    int i = 0, j;

    fseek(f, 0 , SEEK_SET);

    printf("Koji film zelite da obrisete (naziv)");
    scanf("%s", naz);
    printf("%s", naz);


    while(fgetc(f) != EOF){
            printf("DEBUG 1");

        fseek(f, -1, SEEK_CUR);
        fgets(str, 60, f);
        if(strstr(str, naz) != NULL){
                printf("DEBUG 2");

            do{
                printf("DEBUG 3");
                fgets(str, 60 , f);
                if(strstr(str, "Trajanja") != NULL){goto label;}
            }while(strstr(str, "Trajanja") == NULL);


        }
        fputs(str, p);
    }
    label:

        fclose(f);
        fclose(p);

        remove("Filmovi.txt");
        rename("Temp.txt", "Filmovi.txt");

        while(i < id){
            if(Filmovi[i].naziv == naz){

                for(j = i; j<id; j++){
                strcpy(Filmovi[j].naziv, Filmovi[j+1].naziv);
                Filmovi[j].id = Filmovi[j + 1].id;
                strcpy(Filmovi[j].imeRezisera, Filmovi[j + 1].imeRezisera);
                Filmovi[j].duzinaTrajanja = Filmovi[j + 1].duzinaTrajanja;
                Filmovi[j].prosecnaOcena  = Filmovi[j + 1].prosecnaOcena;
                strcpy(Filmovi[j].zanr, Filmovi[j + 1].zanr);
                Filmovi[j].Datum = Filmovi[j + 1].Datum;
                Filmovi[j].brojOcena = Filmovi[j + 1].brojOcena;
                strcpy(Filmovi[j].Glumci, Filmovi[j + 1].Glumci);
                strcpy(Filmovi[j].datumGlumci, Filmovi[j + 1].datumGlumci);

            }}
            i++;
        }

return p;
}
FILE * oceni(int id, FILE * f){

    char naz[60], ocena, str[60];
    int ocenaInt, i = 0, x;

    FILE * p = fopen("Temp.txt", "a+");

    printf("\n\nKoji film (Unesite Naziv, _ u mesto razmaka):");
    printf(">");
    scanf("%s", naz);
    printf("%s", naz);

    printf("\n\nOceni:");
    scanf(" %c", &ocena);

    ocenaInt = ocena - '0';

    while(i < id){


        if(strstr(Filmovi[i].naziv,naz)!= NULL){

            Filmovi[i].prosecnaOcena = ((Filmovi[i].prosecnaOcena * Filmovi[i].brojOcena) + ocenaInt) / (Filmovi[i].brojOcena+1);
            Filmovi[i].brojOcena++;
            x = i;

        }

        i++;
    }

    fseek(f, 0, SEEK_SET);

    while(fgetc(f) != EOF){
        fseek(f, -1, SEEK_CUR);
        fgets(str, 60, f);
        if(strstr(str, naz) != NULL){
                fputs(str, p);
            while(fgetc(f) != EOF){
                fseek(f, -1, SEEK_CUR);
                fgets(str, 60, f);

                if(strstr(str, "Prosecna ocena:") != NULL){

                    fputs("Prosecna ocena: ", p);
                    fprintf(p, "%f", Filmovi[x].prosecnaOcena);

                    fputs("\n\nBroj Ocena: ", p);
                    fprintf(p, "%i", Filmovi[x].brojOcena);
                    fputs("\n", p);
                    fgets(str, 60, f);
                    fgets(str, 60, f);

                }else{fputs(str, p);}


            }


        }

    if(strstr(str, "Duzina Trajanja: ")!= NULL){
            fclose(f);
            fclose(p);

            remove("Filmovi.txt");
            rename("Temp.txt", "Filmovi.txt");


            return p;}
    fputs(str, p);

    }
    fclose(f);
    fclose(p);

    remove("Filmovi.txt");
    rename("Temp.txt", "Filmovi.txt");

return p;}

int main()
{

    int id = 0;

    Niz *pNiz = (Niz*)malloc(sizeof(Niz));
    init_array(pNiz);

    FILE* f = fopen("Filmovi.txt", "a+");

    int x;

    id = ucitajFilmove(f);


    label:

    printf(NOVIFILM);
    printf("\n");
    printf(ISPISFILM);
    printf("\n");
    printf(PRETRAGA);
    printf("\n");
    printf(IZMENA);
    printf("\n");
    printf(BRISANJE);
    printf("\n");
    printf(OCENA);
    printf("\n");
    printf(PREPORUKA);


    printf("\n");
    printf(">");
    scanf("%i", &x);



    switch(x){
        case 0:

            return 0;

        case 1:

           id = NoviFIlm(f, id, pNiz);
           goto label;

        case 2:

           ispisSvihFilmova(id);
           goto label;

        case 3:

            search(id);
            goto label;

        case 4:

            f = izmenaFilma(id ,f);
            goto label;

        case 5:

            f = obrisi(id, f);
            id--;
            goto label;

        case 6:
            f = oceni(id, f);
            goto label;
        case 7:
            preporuci(id);
            goto label;
    }


    return 0;

}
