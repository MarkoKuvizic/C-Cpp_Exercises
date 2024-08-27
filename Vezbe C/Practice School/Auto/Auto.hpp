#ifndef AUTO_HPP_INCLUDED
#define AUTO_HPP_INCLUDED

#include <iostream>

using namespace std;

enum tipStanje {UGASEN = 1, VOZI, POKVAREN };

class Auto{
private:
    Menjac m;
    Skoljka s;
    int trnBrzina;
    tipStanje stanje;

public:
    Auto() : m(), s()
};


#endif // AUTO_HPP_INCLUDED
