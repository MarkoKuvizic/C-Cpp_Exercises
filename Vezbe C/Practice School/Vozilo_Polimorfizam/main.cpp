#include <iostream>

using namespace std;

enum tipGume{LETNJE = 1, ZIMSKE};

class Vozilo{
protected:
    int brzina;
public:
    int kreciSe(){return brzina;}
    virtual void ispis() = 0;

    virtual ~Vozilo(){cout << "Ovo je destruktor za vozilo" << endl;}
};

class Automobil : public Vozilo{
protected:
    tipGume tipGuma;
public:
    Automobil(tipGume tip, int bb){
        tipGuma = tip;
        brzina = bb;
    }
    ~Automobil(){cout << "Ovo je destruktor za automobil" << endl;}
    int kreciSe(){return brzina;}
    void ispis(){
        if(tipGuma = LETNJE){cout << "LETNJE" << endl;}
        else if(tipGuma = ZIMSKE){cout << "ZIMSKE" << endl;}
    }

};

class Avion : public Vozilo{
protected:
    int visina;
public:
    Avion(int vv, int bb){
        visina = vv;
        brzina = bb;
    }
    ~Avion(){cout << "Ovo je destruktor za avion" << endl;}

    int kreciSe(){return brzina;}
    void ispis(){
        cout << "Visina je " << visina << endl;
    }
    friend ostream &operator<<(ostream& output, const Avion &aa){
        output << "*overloaded* Visina je " << aa.visina << endl;
        return output;
    }
    friend istream &operator>>(istream &input, Avion &aa){
        input >> aa.visina;
        return input;
    }
};

int main()
{
    Automobil a(LETNJE, 80);
    Avion av(4000, 600);

    Vozilo *ap = &a;
    Vozilo *avp = &av;

    cout << "Brzina Automobila Je: " << ap->kreciSe() << endl;
    ap->ispis();

    cout << "Brzina Aviona Je: " << avp->kreciSe() << endl;
    avp->ispis();

    cout << av;

    cin >> av;
    cout << av;

    return 0;
}
