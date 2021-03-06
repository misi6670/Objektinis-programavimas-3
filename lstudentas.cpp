#include "lstudentas.h"

Lstudentas::Lstudentas(const Lstudentas& stud)
    : Zmogus(stud.Vardas_, stud.Pavarde_), 
    nd_{ stud.nd_ },
    n_{ stud.n_ },
    egz_{ stud.egz_ },
    galutinis_{ stud.galutinis_ },
    vid_{ stud.vid_ },
    med_{ stud.med_ },
    vidarmed_{ stud.vidarmed_ } {
    Vardas_ = stud.Vardas_;
    Pavarde_ = stud.Pavarde_;
    nd_ = stud.nd_;
    n_ = stud.n_;
    egz_ = stud.egz_;
    galutinis_ = stud.galutinis_;
    vid_ = stud.vid_;
    med_ = stud.med_;
    vidarmed_ = stud.vidarmed_;
}

Lstudentas& Lstudentas::operator=(const Lstudentas& stud) {
    if (&stud == this) return *this;
    nd_.clear();
    Vardas_ = stud.Vardas_;
    Pavarde_ = stud.Pavarde_;
    nd_ = stud.nd_;
    n_ = stud.n_;
    egz_ = stud.egz_;
    galutinis_ = stud.galutinis_;
    vid_ = stud.vid_;
    med_ = stud.med_;
    vidarmed_ = stud.vidarmed_;
    return *this;
}

float Lstudentas::countVidurkis() { 
    float suma = 0; 
    for (float a : nd_) suma = suma + a; 
    return vid_ = suma / n_;
}

float Lstudentas::countMediana() {
    nd_.sort();
    auto itr = nd_.begin();
    if (nd_.size() % 2 == 0) {
        for (int i = 0; i < nd_.size() / 2; i++) itr++;
        return med_ = ((double)*itr + *--itr) / 2;
    }
    else {
        for (int i = 0; i < nd_.size() / 2; i++) itr++;
        return med_ = *itr;
    }
}

float Lstudentas::countGalutinis(float vam) { 
    return galutinis_ = vam * 0.4 + (float)egz_ * 0.6; 
}

bool Lstudentas::operator <(const Lstudentas& a) const {
    if (getVardas() != a.getVardas())
        return getVardas().compare(a.getVardas()) < 0;

    if (getPavarde() != a.getPavarde())
        return getPavarde().compare(a.getPavarde()) < 0;

    return (getGalutinis() > a.getGalutinis());
}

void Lstudentas::isvedimas(char separator, int VardSimb, int PavSimb, int GalutSimb) {
    const char separator_ = separator;
    const int VardSimb_ = VardSimb;
    const int PavSimb_ = PavSimb;
    const int GalutSimb_ = GalutSimb;
    Zmogus::isvedimas(separator_, VardSimb_, PavSimb_);
    cout << left << setw(GalutSimb_) << setfill(separator_) << fixed << setprecision(2) << getGalutinis() << endl;
}
