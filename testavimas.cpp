#include "testavimas.h"

void test(string txt, int duomsk, int StudSkai, int VidArMed)
{
    vector <Studentas> nuskaitytas;
    vector <Studentas> grupe;
    vector <Studentas> grupe1;
    int ndsk = 0;

    cout << endl;
    generavimas(txt + ".txt", duomsk, ndsk);
    cout << "Failo is " << duomsk << " irasu (namu darbu skaicius: " << ndsk << ") testas: " << endl;

    nuskaitymas(txt, grupe, StudSkai, VidArMed);
    auto start = high_resolution_clock::now();
    padalinimas2(grupe, grupe1);
    duration<double> diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant vektoriu ir greiciausia strategija uztruko: " << diff.count() << " s\n";    
    cout << endl;

    grupe1.clear();
    grupe.clear();
}
