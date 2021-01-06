#pragma once
 
#include "zmogus.h"
#include <list>
#include <algorithm>

using std::list;
using std::sort;
using std::count;

class Lstudentas : public Zmogus
{
private:
    list <int> nd_;
    int n_;
    int egz_;
    float galutinis_;
    float vid_;
    float med_;
    int vidarmed_;
public:
    Lstudentas() {
        Vardas_ = "";
        Pavarde_ = "";
        n_ = 0;
        egz_ = 0;
        galutinis_ = 0;
        vid_ = 0;
        med_ = 0;
        vidarmed_ = 0;
    }
    Lstudentas(int vidmed, string vardas, string pavarde, int ndsk, list<int> nd, int egzaminas) {
        vidarmed_ = vidmed;
        Vardas_ = vardas;
        Pavarde_ = pavarde;
        n_ = ndsk;
        nd_ = nd;
        egz_ = egzaminas;
        vid_ = countVidurkis();
        med_ = countMediana();
        setGalutinis();
    }
    Lstudentas(string vardas, string pavarde, int ndsk, list<int> nd, int egzaminas) {
        vidarmed_ = 0;
        Vardas_ = vardas;
        Pavarde_ = pavarde;
        n_ = ndsk;
        nd_ = nd;
        egz_ = egzaminas;
        vid_ = 0;
        med_ = 0;
        galutinis_ = 0;
    }
    ~Lstudentas() { nd_.clear(); }
    Lstudentas(const Lstudentas& stud);
    Lstudentas& operator=(const Lstudentas& stud);
    void setVidarmed(int vam) { vidarmed_ = vam; }
    int getVidarmed() const { return vidarmed_; }
    void setND(list <int> nd) { nd_ = nd; vid_ = countVidurkis(); med_ = countMediana(); }
    list<int> getND() const { return nd_; }
    void setNDskaicius(int ndsk) { n_ = ndsk; }
    int getNDskaicius() const { return n_; }
    void setEgzaminas(int egzaminas) { egz_ = egzaminas; }
    int getEgzaminas() const { return egz_; }
    void setGalutinis() { if (vidarmed_ == 1) galutinis_ = countGalutinis(med_); else galutinis_ = countGalutinis(vid_); }
    float getGalutinis() const { return galutinis_; }
    float countVidurkis();
    float countMediana();
    float countGalutinis(float vam);
    bool operator <(const Lstudentas& a) const;
    void isvedimas(char separator, int VardSimb, int PavSimb, int GalutSimb);
};
