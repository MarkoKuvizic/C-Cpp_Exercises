#ifndef Ucenik_HPP_INCLUDED
#define Ucenik_HPP_INCLUDED

#include <cstdlib>
#include "Skola.hpp"
#include "DjackaKnjizica.hpp"

using namespace std;

enum tipPozicija {KUCA = 1, BIBLIOTEKA, UCIONICA, TRENING};

class Ucenik{

private:

    Skola s;
    DjackaKnjizica d;
    int vestina;
    int znanje;
    int odmor;
    tipPozicija pozicija;

public:

    //konstruktori
    Ucenik() : s(), d(){
        vestina = 50;
        znanje = 20;
        odmor = 70;
        pozicija = KUCA;
    }
    Ucenik(double pp, int gg, tipVrstaSkole vv, tipStepenSkole ss, int ves, int zna, int odm, tipPozicija poz) : d(pp, gg), s(vv, ss){
        vestina = ves;
        znanje = zna;
        odmor = odm;
        pozicija = poz;
    }

    //geteri
    int getVestina()const{return vestina;}
    int getZnanje()const{return znanje;}
    int getOdmor()const{return odmor;}
    tipPozicija getPozicija()const{return pozicija;}
    DjackaKnjizica getDjackaKnjizica()const{return d;}

   //metode
   //nema uslova za idi kuci, uvek moze, pa ne trb da bude bool
   void idiKuci(){
        pozicija = KUCA;
   }
   bool idiNaTrening(){
        if(pozicija == KUCA && odmor > 60){
                pozicija = TRENING;
                return true;
        }else{return false;}
   }
   bool idiUBibilioteku(){
        if(pozicija == KUCA || pozicija == UCIONICA){
            pozicija = BIBLIOTEKA;
            return true;
        }else{return false;}
   }
   bool idiUUcionicu(){
        if(pozicija == BIBLIOTEKA){
            pozicija = UCIONICA;
            return true;
        }else{return false;}
   }
   bool spavaj(int sati){
        if(sati < 2 || sati > 18){
            return false;
        }

        odmor += sati * 10;

        if(odmor > 100){
            odmor = 100;
        }
        return true;
    }
   bool uci(){

        if(pozicija != BIBLIOTEKA){return false;}

        int t = rand() % 10 + 1;
        znanje += t;

        if(znanje > 100){znanje = 100;}
        return true;
   }
   bool treniraj(){

        if(pozicija != TRENING){return false;}

        int t = rand() % 10 + 1;
        vestina += t;

        if(vestina > 100){vestina = 100;}
   }
   double poloziGodinu(){
        int ocena, gg = d.getGodina();
        double pp = d.getProsek(), tmp;

        if(pozicija != UCIONICA || znanje < 61){return NULL;}

        if(znanje >= 90){ocena = 5;}
        else if(znanje >= 80){ocena = 4;}
        else if(znanje >= 70){ocena = 3;}
        else if(znanje >= 60){ocena = 2;}

        tmp = pp * gg;
        tmp += ocena;
        d.setGodina(gg+1);
        gg++;
        pp = tmp/gg;
        d.setProsek(pp);

        switch(s.getStepen()){
            case TROGODISNJA:
            if(d.getGodina() == 3)
            {
                if(maturiraj() == true)
                {
                    cout<< "Cestitam, maturirao si, ides kuci"<<endl;
                    idiKuci();
                }else{cout<< "Ovo je poslednja godina, ali nisi imao srece, pa nisi maturirao"<<endl;}
            }
                break;
            case CETVOROGODISNJA:
            if(d.getGodina() == 4)
            {
                if(maturiraj() == true)
                {
                    cout<< "Cestitam, maturirao si, ides kuci"<<endl;
                    idiKuci();
                }
                else
                {
                    cout<< "Ovo je poslednja godina, ali nisi imao srece, pa nisi maturirao"<<endl;
                }
            }
                break;
        }
        return d.getProsek();

   }
   bool maturiraj(){

        int t = rand() % 10 + 1;
        if(t > 1)
        {
            return true;
        }
        else{return false;}

   }
};


#endif // Ucenik_HPP_INCLUDED
