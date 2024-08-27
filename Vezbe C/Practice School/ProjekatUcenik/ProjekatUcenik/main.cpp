#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Ucenik.hpp"

using namespace std;

void kuci(Ucenik& u){

    cout <<"----------KUCA----------"<< endl << endl;

    cout << "1. Idi u biblioteku"<< endl;
    cout << "2. Idi na trening"<< endl;
    cout << "3. Spavaj"<< endl;

    label:

    int s;
    int a;
    cin>>a;

    switch(a){
        case 1:
            u.idiUBibilioteku();
            break;
        case 2:
            u.idiNaTrening();
            break;
        case 3:
            cout<<"Koliko Sati"<<endl;
            cin>>s;
            cout<<"Spavao sam, trenutni odmor:"<< u.getOdmor()<<endl;
            if(u.spavaj(s) == true){goto label;}
            else{cout<<"Ne Moze"<<endl;
                goto label;
            }

    }
}
void trening(Ucenik& u){
    cout <<"----------TRENING----------"<< endl << endl;

    cout << "1. Idi kuci"<< endl;
    cout << "2. Treniraj"<< endl;

    int a;

    label3:

    cin>>a;

    switch(a){
        case 1:
            u.idiKuci();
            break;
        case 2:
            if(u.treniraj() == true)
            {
                cout<<"trenirao sam, trenutna vestina: "<<u.getVestina()<<endl;
                goto label3;
            }
            else{
                cout<<"Ne Moze"<< endl;
                goto label3;
            }
        }


}

void biblioteka(Ucenik& u){

    cout <<"----------BIBLIOTEKA----------"<< endl << endl;

    cout << "1. Idi u ucionicu"<< endl;
    cout << "2. Idi kuci"<< endl;
    cout << "3. Uci"<< endl;

    int a;
    label4:
    cin>>a;

    switch(a){
    case 1:
        u.idiUUcionicu();
        break;
    case 2:
        u.idiKuci();
        break;
    case 3:
        if(u.uci()== true){cout << "Ucio Sam, trenutno znanje: " << u.getZnanje() << endl; }
        goto label4;
    }

}

void ucionica(Ucenik& u){
    cout <<"----------UCIONICA----------"<< endl << endl;

    cout << "1. Idi u biblioteku"<< endl;
    cout << "2. Idi kuci"<< endl;
    cout << "3. Polozi godinu (Napomena: ne moze da se maturira direktno iz ovog menija, ako polozite odgovarajucu godinu, funkcija se poziva odavde)"<< endl;

    int a;
    label5:
    cin >> a;

    switch(a){
        case 1:
            u.idiUBibilioteku();
            break;
        case 2:
            u.idiKuci();
            break;
        case 3:
            double pp = u.poloziGodinu();

            if(pp != NULL){

                cout << "Uspesno polozena godina, prosek: " << pp << endl;
                goto label5;

            }else{cout << "Nije uspesno polozena godina, verovatno zbog lose ocene" << endl;}

    }

}

int main()
{
    Ucenik u;
    Ucenik u1(5.00, 1, GIMNAZIJA, CETVOROGODISNJA, 70, 40, 20, KUCA);
    srand((unsigned)time(0));

    label2:

    switch(u.getPozicija()){
        case KUCA:
            kuci(u);
            //cout<<"izasao sam"<< endl;
            goto label2;
        case TRENING:
            trening(u);
            goto label2;
        case UCIONICA:
            ucionica(u);
            goto label2;
        case BIBLIOTEKA:
            biblioteka(u);
            goto label2;
            break;
    }


}
