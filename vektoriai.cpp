#include "vektoriai.h"

void nuskaitymas(string txtname, vector<Studentas>& grupe, int& StudSkai, int VidArMed)
{
    int NamuDarbuSk;
    int pirmas = 0;
    vector<string> eilute;
    string eil;
    ifstream f(txtname + ".txt");

    while (f) {
        if (!f.eof()) {
            std::getline(f, eil);
            eilute.push_back(eil);
        }
        else break;
    }
    f.close();

    for (auto str : eilute) {
        if (pirmas == 0) {
            NamuDarbuSk = count(str.begin(), str.end(), 'N');
            pirmas = 1;
        }
        else {
            string Vardas;
            string Pavarde;
            vector <int> nd;
            int n = NamuDarbuSk;
            int egz;
            for (int i = 0; i < str.length(); i++)
            {
                if (str.at(i) >= 'A' && str.at(i) <= 'Z') {
                    if (Vardas == "")
                        while (str.at(i) != ' ') {
                            Vardas += str.at(i);
                            i++;
                        }
                    else
                        while (str.at(i) != ' ') {
                            Pavarde += str.at(i);
                            i++;
                        }
                }
                else if (isdigit(str.at(i))) {
                    int a = i + 1;
                    if (i == str.length() - 2) {
                        egz = (str.at(i) - '0') * 10 + (str.at(a) - '0');
                        i++;
                    }
                    else if (i == str.length() - 1) {
                        egz = str.at(i) - '0';
                    }
                    else {
                        int paz = 0;
                        if (str.at(a) == ' ') paz = str.at(i) - '0';
                        else {
                            paz = (str.at(i) - '0') * 10 + (str.at(a) - '0');
                            i++;
                        }
                        nd.push_back(paz);
                    }
                }
            }
            Studentas stud(VidArMed, Vardas, Pavarde, n, nd, egz);
            grupe.push_back(stud);
            nd.clear();
        }
    }
}

void ivedimas(vector<Studentas>& grupe, int StudSkai, int VidArMed, int AutoGen)
{
    for (int i = 0; i < StudSkai; i++) {
        string Vardas;
        string Pavarde;
        vector <int> nd;
        int n = 0;
        int egz;

        cout << "\n Iveskite " << i + 1 << " studento varda ir pavarde \n";
        cin >> Vardas >> Pavarde;

        if (AutoGen == 1) {
            cout << "\n" << i + 1 << " studento atsitiktinai sugeneruoti pazymiai: \n";
            n = autosk(1, 15);
            for (int j = 0; j < n; j++) {
                int random;
                random = autosk(1, 10);
                cout << random << " ";
                nd.push_back(random);
            }
            cout << endl;
            egz = autosk(1, 10);
            cout << "\n" << i + 1 << " studento atsitiktinai sugeneruotas egzamino balas: " << egz << endl;
        }
        else {
            cout << "\n Iveskite " << i + 1 << " studento pazymius, suvedus visus pazymius irasykite 0\n";
            int nulis = 1;
            while (nulis != 0) {
                int paz;
                cin >> paz;
                skaitymoKlaidosPaz(paz, n);
                if (paz == 0) nulis = 0;
                else {
                    nd.push_back(paz);
                    n++;
                    nd.reserve(n);
                    cout << "Ivedete " << n << " pazymi(-ius)" << endl;
                }
            }
            cout << "\n Iveskite " << i + 1 << " studento egzamino rezultata \n";
            cin >> egz;
            skaitymoKlaidosPaz(egz, -1);
        }
        Studentas stud(VidArMed, Vardas, Pavarde, n, nd, egz);
        grupe.push_back(stud);
        nd.clear();
    }
}

int autosk(int nuo, int iki)
{
    using hrClock = high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(nuo, iki);
    int sk = dist(mt);
    return sk;
}

void isvedimas(vector<Studentas> grupe, int VidArMed)
{
    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int GalutSimb = 16;

    sort(grupe.begin(), grupe.end());
    cout << endl;
    cout << left << setw(VardSimb) << setfill(separator) << "Vardas";
    cout << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    if (VidArMed == 1) cout << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Med.)" << endl;
    else cout << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Vid.)" << endl;
    cout << string(VardSimb + PavSimb + GalutSimb, '-') << endl;
    for (auto& tt : grupe) tt.isvedimas(separator, VardSimb, PavSimb, GalutSimb);
}

void irasymas(string name, vector<Studentas> grupe, int VidArMed)
{
    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int GalutSimb = 16;
    ofstream f(name);

    sort(grupe.begin(), grupe.end());
    f << left << setw(VardSimb) << setfill(separator) << "Vardas";
    f << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    if (VidArMed == 1) f << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Med.)" << endl;
    else f << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Vid.)" << endl;
    f << string(VardSimb + PavSimb + GalutSimb, '-') << endl;
    for (auto& tt : grupe) {
        f << left << setw(VardSimb) << setfill(separator) << tt.getVardas();
        f << left << setw(PavSimb) << setfill(separator) << tt.getPavarde();
        f << left << setw(GalutSimb) << setfill(separator) << fixed << setprecision(2) << tt.getGalutinis() << endl;
    }
    f.close();
}

void padalinimas(vector<Studentas>& grupe, vector<Studentas>& grupe1)
{
    vector<Studentas> grupe2;
    int sk1 = 0;
    int sk2 = 0;
    for (auto& tt : grupe) {
        if (tt.getGalutinis() < 5) {
            grupe1.push_back(tt);
            sk1++;
            grupe1.reserve(sk1);
        }
        else {
            grupe2.push_back(tt);
            sk2++;
            grupe2.reserve(sk2);
        }
    }
    grupe = grupe2;
    grupe2.clear();
}

void padalinimas1(vector<Studentas> grupe, vector<Studentas>& grupe1, vector<Studentas>& grupe2)
{
    int sk1 = 0;
    int sk2 = 0;
    for (auto& tt : grupe) {
        if (tt.getGalutinis() < 5) {
            grupe1.push_back(tt);
            sk1++;
            grupe1.reserve(sk1);
        }
        else {
            grupe2.push_back(tt);
            sk2++;
            grupe2.reserve(sk2);
        }
    }
}

void padalinimas2(vector<Studentas>& grupe, vector<Studentas>& grupe1)
{
    vector<Studentas> grupe2;
    int sk1 = 0;
    for (auto& tt : grupe) {
        if (tt.getGalutinis() < 5) {
            grupe1.push_back(tt);
            sk1++;
            grupe1.reserve(sk1);
        }
    }
    grupe.erase(std::remove_if(grupe.begin(), grupe.end(), [&](Studentas& studentas) {
        return studentas.getGalutinis() < 5; }), grupe.end());
}

void generavimas(string txt, int sk, int& ndsk)
{
    vector<Studentas> grupe;

    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int NdSimb = 5;

    string Vardas;
    string Pavarde;
    vector <int> nd;
    int n = 0;
    int egz;

    ofstream f(txt);

    grupe.reserve(sk);
    if (sk <= 1000) ndsk = autosk(1, 15);
    else if (sk <= 100000) ndsk = autosk(1, 10);
    else ndsk = autosk(1, 5);

    for (int i = 0; i < sk; i++) {
        n = ndsk;
        zmogausVP(Vardas, Pavarde);
        for (int j = 0; j < n; j++) {
            int random;
            random = autosk(1, 10);
            nd.push_back(random);
        }
        egz = autosk(1, 10);
        Studentas stud(Vardas, Pavarde, n, nd, egz);
        grupe.push_back(stud);
        nd.clear();
    }

    f << left << setw(VardSimb) << setfill(separator) << "Vardas";
    f << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    for (int i = 0; i < ndsk; i++) f << left << setw(NdSimb) << setfill(separator) << "ND" + to_string(i + 1);
    f << "Egz." << endl;

    for (auto& tt : grupe) {
        f << left << setw(VardSimb) << setfill(separator) << tt.getVardas();
        f << left << setw(PavSimb) << setfill(separator) << tt.getPavarde();
        for (auto& ss : tt.getND()) f << left << setw(NdSimb) << ss;
        f << tt.getEgzaminas();
        if (&tt != &grupe.back()) f << endl;
    }

    f.close();
    grupe.clear();
}

void zmogausVP(string& vardas, string& pavarde) {

    map<int, string> vardai, pavardes_m, pavardes_v;

    vardai[100] = "Irma";
    vardai[101] = "Alma";
    vardai[102] = "Irena";
    vardai[103] = "Egle";
    vardai[104] = "Jolanta";
    vardai[105] = "Julija";
    vardai[106] = "Goda";
    vardai[107] = "Kotryna";
    vardai[108] = "Ugne";
    vardai[109] = "Saule";
    vardai[110] = "Auguste";
    vardai[111] = "Milda";
    vardai[112] = "Gabija";
    vardai[113] = "Teja";
    vardai[114] = "Orinta";
    vardai[115] = "Emilija";
    vardai[116] = "Ilona";
    vardai[117] = "Sigita";
    vardai[118] = "Evelina";
    vardai[119] = "Aurelija";

    vardai[120] = "Petras";
    vardai[121] = "Jonas";
    vardai[122] = "Ignas";
    vardai[123] = "Darius";
    vardai[124] = "Simas";
    vardai[125] = "Paulius";
    vardai[126] = "Donatas";
    vardai[127] = "Rytis";
    vardai[128] = "Saulius";
    vardai[129] = "Valdas";
    vardai[130] = "Saulius";
    vardai[131] = "Gytis";
    vardai[132] = "Jokubas";
    vardai[133] = "Aurimas";
    vardai[134] = "Gvidas";
    vardai[135] = "Tomas";
    vardai[136] = "Rimas";
    vardai[137] = "Aidas";
    vardai[138] = "Dominykas";
    vardai[139] = "Kipras";

    vardas = vardai[autosk(100, 139)];

    switch (*vardas.rbegin()) {
    case 's':
        pavarde = "Pavardenis" + to_string(autosk(1, 500));
        break;
    default:
        pavarde = "Pavardaite" + to_string(autosk(1, 500));
        break;
    };
}
