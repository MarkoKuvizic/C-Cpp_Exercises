#ifndef DjackaKnjizica_HPP_INCLUDED
#define DjackaKnjizica_HPP_INCLUDED

class DjackaKnjizica{

private:

    double prosek;
    int godina;

public:
    //konstruktori
    DjackaKnjizica(){
        prosek = 5.00;
        godina = 1;
    }
    DjackaKnjizica(double pp, int gg){
        prosek = pp;
        godina = gg;
    }
    DjackaKnjizica(const DjackaKnjizica& d){
        prosek = d.prosek;
        godina = d.godina;
    }

    //geteri
    double getProsek()const{return prosek;}
    int getGodina()const{return godina;}

    //seteri
    bool setProsek(double pp)
    {
        if(pp < 1.00 || pp > 5.00){
            return false;
        }else{
            prosek = pp;
            return true;
        }
    }
    bool setGodina(int gg){
        if(gg < 1 || gg > 4){
            return false;
        }else{
            godina = gg;
            return true;
        }
    }
};

#endif // DjackaKnjizica_HPP_INCLUDED
