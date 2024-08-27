#ifndef Skola_HPP_INCLUDED
#define Skola_HPP_INCLUDED

enum tipVrstaSkole {STRUCNA = 1, GIMNAZIJA, UMETNICKA};
enum tipStepenSkole {TROGODISNJA = 1, CETVOROGODISNJA};

class Skola{

private:

    tipVrstaSkole Vrsta;
    tipStepenSkole Stepen;

public:

    //konstruktori
    Skola(){
        Vrsta = STRUCNA;
        Stepen = TROGODISNJA;
    }
    Skola(tipVrstaSkole vv, tipStepenSkole ss){
        Vrsta = vv;
        Stepen = ss;
    }
    Skola(const Skola& s){
        Vrsta = s.Vrsta;
        Stepen = s.Stepen;
    }

    //geteri
    tipVrstaSkole getVrsta(){return Vrsta;}
    tipStepenSkole getStepen(){return Stepen;}

    //seteri
    void setVrsta(tipVrstaSkole vv){Vrsta = vv;}
    void setStepen(tipStepenSkole ss){Stepen = ss;}

};

#endif // Skola_HPP_INCLUDED
