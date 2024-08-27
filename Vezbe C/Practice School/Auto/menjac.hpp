#ifndef MENJAC_HPP_INCLUDED
#define MENJAC_HPP_INCLUDED

#include <iostream>

using namespace std;

enum tipTipMenjaca {AUTOMATIK = 1, MANUELNI};


class Menjac{

private:
    int brzine;
    tipTipMenjaca tip;

public:
    Menjac(){
        brzine = 5;
        tip = MANUELNI;
    }
    Menjac(int bb, tipTipMenjaca tt){
        brzine = bb;
        tip = tt;
    }
    Menjac(Menjac& m){
        brzine = m.brzine;
        tip = m.tip;
    }

    void setBrzine(int bb){brzine = bb;}
    void setTip(tipTipMenjaca tt){tip = tt;}

    int getBrzine(){return brzine;}
    tipTipMenjaca getTip(){return tip;}

 };

#endif // MENJAC_HPP_INCLUDED
