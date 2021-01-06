#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::string;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;

class Zmogus
{
protected:
    string Vardas_;
    string Pavarde_;
    Zmogus() {
        Vardas_ = "";
        Pavarde_ = "";
    }
    Zmogus(string vardas, string pavarde) {
        Vardas_ = vardas;
        Pavarde_ = pavarde;
    }
    Zmogus(const Zmogus& zmg);
    Zmogus& operator=(const Zmogus& zmg);
    void setVardas(string vardas) { Vardas_ = vardas; }
    void setPavarde(string pavarde) { Pavarde_ = pavarde; }
public:
    virtual ~Zmogus() { }
    virtual string getVardas() const { return Vardas_; }
    virtual string getPavarde() const { return Pavarde_; }
    virtual bool operator <(const Zmogus& a) const;
    virtual void isvedimas(char separator, int VardSimb, int PavSimb);
};
