#include <iostream>

using namespace std;

#include "list"

enum vrstaKarte {REGULARNA = 1, SEZONSKA, STUDENTSKA, GRUPNA, POCASNA};
enum dostupnostSedista {SLOBODNO= 1, REZERVISANO, PRODATO};

class Karta{
protected:
    int id;
    vrstaKarte vrsta;
public:
    Karta(){
        id=0;
        vrsta = REGULARNA;
            }
    Karta(int i, vrstaKarte v){
        id = i;
        vrsta = v;
    }
    int getID(){return id;}
    vrstaKarte getVrsta(){return vrsta;}

    friend ostream& operator<<(ostream& output, Karta& K){
        output << "Vrsta Karte: " << K.vrsta << " ID: " << K.id << endl;
        return output;
    }
};

template <int Br>

class Pozoriste{
public:
    Karta Mesta[Br];
    dostupnostSedista Dos[Br];

    Pozoriste(){
        for(int i = 0; i <= Br; i++){
            Mesta[i] = new Karta;
            Dos[i] = SLOBODNO;
        }
    }
    int brSlobodnihSedista(){
        int n;
        for(int i = 0; i <= Br; i++){
           if(Dos[i] == SLOBODNO){n++;}
           return n;
        }
    }
    bool rezervisiSediste(Karta &k, int n){
        if(Dos[n] == SLOBODNO){
            Mesta[n].id = k.id ;
            Mesta[n].vrsta = k.vrsta;
            Dos[n] = REZERVISANO;
            return true;
        }else {return false;}
    }
    int rezervisiSediste(Karta &k){
        for(int i = 0; i <= Br; i++){
           if(Dos[i] == SLOBODNO){
                Mesta[i].id = k.id ;
                Mesta[i].vrsta = k.vrsta;
                Dos[i] == REZERVISANO;
                return i;}
        }
        return -1;
    }
    bool ProdajSediste(Karta &k, int n){
        if(Dos[n] == SLOBODNO){
            Mesta[n].id = k.id ;
            Mesta[n].vrsta = k.vrsta;
            Dos[n] = PRODATO;
            return true;
        }else {return false;}
                                }
    int ProdajSediste(Karta &k){
        for(int i = 0; i <= Br; i++){
           if(Dos[i] == SLOBODNO){
                Mesta[i].id = k.id ;
                Mesta[i].vrsta = k.vrsta;
                Dos[i] == PRODATO;
                return i;}
        }
        return -1;
    }
    bool ponistiRez(int kID){
        for(int i = 0; i <= Br; i++){
           if(Mesta[i].getID() == kID ){
                Dos[i] == SLOBODNO;
                return true;}
        }
        return false;
    }
    Karta getKarta(int br){
        return Mesta[br];
    }
};

int main()
{
    return 0;
}
