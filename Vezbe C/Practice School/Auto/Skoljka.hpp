#ifndef SKOLJKA_HPP_INCLUDED
#define SKOLJKA_HPP_INCLUDED

#include <iostream>

using namespace std;

enum tipBoje {PLAVA = 1, CRVENA, ZELENA};


class Skoljka {
private:
    tipBoje boja;
public:
    Skoljka(){boja = PLAVA;}
    Skoljka(tipBoje bb){boja = bb;}
    Skoljka(Skoljka& s){boja = s.boja;}

    void setBoja(tipBoje bb){boja = bb;}

    tipBoje getBoja(){return boja;}

};

#endif // SKOLJKA_HPP_INCLUDED
