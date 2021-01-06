#pragma once

#include "klaidos.h"
#include "studentas.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <random>
#include <map>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;
using std::sort;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::ios;
using std::count;
using std::to_string;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::map;

void nuskaitymas(string txtname, vector<Studentas>& grupe, int& StudSkai, int VidArMed);
void ivedimas(vector<Studentas>& grupe, int StudSkai, int VidArMed, int AutoGen);
int autosk(int nuo, int iki);
void isvedimas(vector<Studentas> grupe, int VidArMed);
void irasymas(string name, vector<Studentas> grupe, int VidArMed);
void padalinimas(vector<Studentas>& grupe, vector<Studentas>& grupe1);
void padalinimas1(vector<Studentas> grupe, vector<Studentas>& grupe1, vector<Studentas>& grupe2);
void padalinimas2(vector<Studentas>& grupe, vector<Studentas>& grupe1);
void generavimas(string txt, int sk, int& ndsk);
void zmogausVP(string& vardas, string& pavarde);
