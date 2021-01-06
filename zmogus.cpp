#include "zmogus.h"

Zmogus::Zmogus(const Zmogus& zmg)
    : Vardas_{ zmg.Vardas_ },
    Pavarde_{ zmg.Pavarde_ } {
    Vardas_ = zmg.Vardas_;
    Pavarde_ = zmg.Pavarde_;
}

Zmogus& Zmogus::operator=(const Zmogus& zmg) {
    if (&zmg == this) return *this;
    Vardas_ = zmg.Vardas_;
    Pavarde_ = zmg.Pavarde_;
    return *this;
}

bool Zmogus::operator <(const Zmogus& a) const {
    if (getVardas() != a.getVardas())
        return getVardas().compare(a.getVardas()) < 0;

    return getPavarde().compare(a.getPavarde()) < 0;
}

void Zmogus::isvedimas(char separator, int VardSimb, int PavSimb) {
    const char separator_ = separator;
    const int VardSimb_ = VardSimb;
    const int PavSimb_ = PavSimb;
    cout << left << setw(VardSimb_) << setfill(separator_) << getVardas();
    cout << left << setw(PavSimb_) << setfill(separator_) << getPavarde();
}
