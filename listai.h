#pragma once

#include "klaidos.h"
#include "lstudentas.h"
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <random>
#include <map>

using std::cout;
using std::cin;
using std::string;
using std::list;
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

void lnuskaitymas(string txtname, list<Lstudentas>& grupe, int& StudSkai, int VidArMed);
void livedimas(list<Lstudentas>& grupe, int StudSkai, int VidArMed, int AutoGen);
int lautosk(int nuo, int iki);
void lisvedimas(list<Lstudentas> grupe, int VidArMed);
void lirasymas(string name, list<Lstudentas> grupe, int VidArMed);
void lpadalinimas(list<Lstudentas>& grupe, list<Lstudentas>& grupe1);
void lpadalinimas1(list<Lstudentas> grupe, list<Lstudentas>& grupe1, list<Lstudentas>& grupe2);
void lpadalinimas2(list<Lstudentas>& grupe, list<Lstudentas>& grupe1);
void lgeneravimas(string txt, int sk, int& ndsk);
void lzmogausVP(string& vardas, string& pavarde);
