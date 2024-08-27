#include <iostream>
#include "list.hpp"
#include "dinstring.hpp"

using namespace std;

class Povrce{
protected:
    float kolicina;
    int cena;
public:
    Povrce(){
        kolicina = 1;
        cena = 50;
            }
    Povrce(float kk, int cc){
        kolicina = kk;
        cena = cc;
    }

    int getCena(){return cena;}

    virtual DinString tipVoca() = 0;
    virtual void ispisi(){
        cout << "Kolicina: " << kolicina << "Cena: " << cena << endl;
    }
};

enum tPap{BABURA = 1, CILI, ROG};

class Paprika : public Povrce{
protected:
    tPap tip;
public:
    Paprika() : Povrce(), tip(BABURA){}
    Paprika(float kk, int cc, tPap tt) : Povrce(kk, cc), tip(tt){}

    DinString tipVoca(){
        DinString d("paprika");
        return d;
    }
    void ispisi(){
        cout << tipVoca() << " Kolicina: " << kolicina << "Cena: " << cena << endl;
    }
};

class Krompir : public Povrce{
public:

    static int brK;

    Krompir() : Povrce(){brK++;}
    Krompir(float kk, int cc) : Povrce(kk, cc){brK++;}

    DinString tipVoca(){
        DinString d("krompir");
        return d;
    }
    void ispisi(){
        cout << tipVoca() << " Kolicina: " << kolicina << "Cena: " << cena << " " <<  brK <<  endl;
    }
};

int Krompir :: brK = 0;

class Luk : public Povrce{
protected:
    bool beli;
public:
    Luk() : Povrce(){beli = false;}
    Luk(float kk, int cc, bool bb) : Povrce(kk, cc){beli = bb;}

    DinString tipVoca(){
        DinString d("Luk");
        return d;
    }
    void ispisi(){
        cout << tipVoca() << " Kolicina: " << kolicina << "Cena: " << cena << " " <<  endl;
        if(beli == true){cout << "beli" << endl;}else{cout << "crni" << endl;}
    }
};

class Tezga{
protected:
    List<Povrce*>lista;
    bool pirocanac;
public:
    Tezga() : lista(){
        pirocanac = false;
    }
    Tezga(bool pp) : lista(){
        pirocanac = pp;
    }

    void nabaviPovrce(Povrce& P){
        lista.add(lista.size() + 1, &P);
    }
    void prodajPovrce(int n){
        lista.remove(n);
    }
    void prodajPovrce(DinString& a){

        Povrce *tmp;

        if(a == "Luk"){
            for(int i = 1; i <= lista.size(); i++){
                lista.read(i, tmp);
                if(tmp->tipVoca() == "Luk"){
                    lista.remove(i);
                }
            }
        }else if(a == "Krompir"){
            for(int i = 1; i <= lista.size(); i++){
                lista.read(i, tmp);
                if(tmp->tipVoca() == "Krompir"){
                    lista.remove(i);
                }
            }
        }else if(a == "Paprika"){
            for(int i = 1; i <= lista.size(); i++){
                lista.read(i, tmp);
                if(tmp->tipVoca() == "Paprika"){
                    lista.remove(i);
                }
            }
        }else if(a == "Sve"){
            for(int i = 1; i <= lista.size(); i++){
                lista.remove(i);
            }
        }
    }
    int rasprodaja(int a){
        Povrce *tmp;
        int x = 0;
        for(int i = 1; i <= lista.size(); i++){
            lista.read(i, tmp);
            if(tmp->getCena() < a){
                lista.remove(i);
                x++;
            }
        }
        return x;
    }
    friend ostream& operator <<(ostream& output, Tezga& T){
        if(pirocanac == true){output << "Pirocanac ";}

    }
};

int main()
{
    Tezga t;
    Luk l;
    t.nabaviPovrce(l);
    DinString d("Luk");
    t.prodajPovrce(d);
    return 0;
}
