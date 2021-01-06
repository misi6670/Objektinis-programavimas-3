# Objektinis programavimas 2
Ši programa nuskaito vartotojų įvedamus duomenis (studento vardą ir pavardę, namų darbų ir egzamino rezultatą). Baigus duomenų įvedimą, suskaičiuoja galutinį balą ir juos pateikia į ekraną. Galutinis balas skaičiuojamas pagal vartotojo pasirinkimą - naudojant vidurkį arba medianą ir yra pateikiamas dviejų skaičių po kablelio tikslumu. Studentai padalinami į dvi kategorijas - "išlaikiusieji" (studentai, kurių galutinis balas >= 5.0) ir "neišlaikiusieji" (studentai, kurių galutinis balas < 5.0) - ir atitinkamai išvedami į du naujus failus - "islaike.txt" ir "neislaike.txt". Studentai išvedami surūšiuoti pagal vardus, pavardes ir galutinį pažymį. Vartotojui pasirinkus, studento pažymius galima generuoti atsitiktinai, duomenis taip pat galima nuskaityti iš failo.
* [V1.0 versija](https://github.com/misi6670/Objektinis-programavimas/releases/tag/V1.0) 
Programa parašyta naudojant struktūrą "studentas".
* [V1.1 versija](https://github.com/misi6670/Objektinis-programavimas-2/releases/tag/V1.1) 
Šioje realizacijoje vietoje struktūros "studentas" naudojama sukurta klasė "Studentas". Vartotojui pasirinkus, galima atlikti programos veikimo greičio (spartos) analizę. Testas atliekamas su 2 failais iš 100000, 1000000 įrašų, testo metu jie yra sugeneruojami ir pasibaigus testavimui ištrinami. Matavimai atliekami su kiekvienu failu. Matuojamas: studentų rūšiavimas į dvi grupes/kategorijas greičiausia strategija, naudojant vektorio tipo konteinerį.
* [V1.2 versija](https://github.com/misi6670/Objektinis-programavimas-2/releases/tag/V1.2) 
Šioje realizacijoje pridėti operatoriai klasėms "Studentas", pagal 3 taisyklę ("Rule of three"), - destruktorius, kopijavimo konstruktorius ir kopijavimo priskirties operatorius.
* [V1.5 versija](https://github.com/misi6670/Objektinis-programavimas-2/releases/tag/V1.5) 
Šioje realizacijoje vietoje vienos Studentas klasės sukurtos dvi: bazinė klasė - Zmogus - skirta bendrai aprašyti žmogų, ir iš jos išvestinė (derived) klasė - Studentas. Bazinė klasė Zmogus yra abstrakčioji klasė, t.y. nėra galima sukurti žmogaus tipo objektų, o tik objektus, gautus iš jos išvestinių klasių.
* [V2.0 versija](https://github.com/misi6670/Objektinis-programavimas-2/releases/tag/V2.0)
Šioje realizacijoje sukurta dokumentacija panaudojant Doxygen. Realizuoti Unit Testai naudojant GoogleTest framework'ą. 
