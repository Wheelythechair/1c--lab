#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <numeric>   //accumulate





struct mokinys {
    std::string Vardas, Pavarde;
    std::vector<int> Pazymys;
};




int failo_ilgis();
void nuskaitymas(std::vector<mokinys>& mok, int ilgis, int ND_kiekis, std::string failas);
void space_remove(mokinys& mok);
double vidurkis(const mokinys& mok);
std::string spacing(const std::string& name, int length);
double mediana(mokinys& mok);
void isvedimas(std::vector<mokinys>& mok);
void generavimas(int mok_kiekis, int ND_kiekis);







int main() {
    int ilgis, ND_kiekis, mok_kiekis;
    char gen;
    std::vector<mokinys> mok;

    std:: cout << "ar norite sugeneruot faila? Spauskite t, jei taip, n, jei ne" << std::endl;
    std::cin >> gen;
    if (gen == 't') {
        std::cout << "kiek mokiniu noretumet sugeneruot ir kiek pazymiu jie gavo?" << std::endl;
        std::cin >> mok_kiekis >> ND_kiekis;
        generavimas(mok_kiekis, ND_kiekis);
        nuskaitymas(mok, failo_ilgis(), ND_kiekis, "kursiokai.txt");      // vykdau nuskaitymo funkcija
    }
    else {
    std::cout << "Kiek ND buvo uzduota?" << std::endl;
    std::cin >> ND_kiekis;
    nuskaitymas(mok, failo_ilgis(), ND_kiekis, "ND.txt");      // vykdau nuskaitymo funkcija
    }



    for (auto& m : mok) {
        space_remove(m);
    }


    isvedimas(mok);  // isvedimo funkcija






    return 0;
}











int failo_ilgis() {
    std::string temp;
    int x = 0;

    std::ifstream df("ND.txt");

    while (std::getline(df, temp)) {  // Count the number of lines
        x++;
    }
    x = x - 1;  // Ignore the first header line
    df.close();
    return x;
}
void nuskaitymas(std::vector<mokinys>& mok, int ilgis, int ND_kiekis, std::string failas) { // funkcijoj sukuriu nauja mokinys struktura ir nuskaicius viska, graziai viska imetu i mokinys mok struktura
    std::string temp;
    char raid[50];  //laikinas char skirtas vardo ir pavardes priskyrimui

    std::ifstream df(failas);
    std::getline(df, temp);  //Praleidziu nereikalinga pirmaja eilute

    for (int i = 0; i < ilgis; i++) {
        mokinys current;
        df.get(raid, 20);  //Perskaitau ir priskyriu varda
        current.Vardas = raid;
        df.get(raid, 26);  //perskaitau ir priskyriu pavarde
        current.Pavarde = raid;

        for (int j = 0; j < ND_kiekis; j++) {  //perskaitau ir priskyriu pazymius
            int Pazymys_temp;
            df >> Pazymys_temp;
            current.Pazymys.push_back(Pazymys_temp);
        }
        std::getline(df, temp);  // praleidziu likusia eilute
        mok.push_back(current);
    }
    df.close();
}
void space_remove(mokinys& mok) {  // funkcija skirtapanaikinti nereikalingus tarpus just in case
    mok.Vardas.erase(std::remove_if(mok.Vardas.begin(), mok.Vardas.end(), ::isspace), mok.Vardas.end());
    mok.Pavarde.erase(std::remove_if(mok.Pavarde.begin(), mok.Pavarde.end(), ::isspace), mok.Pavarde.end());
}
double vidurkis(const mokinys& mok) {
    if (mok.Pazymys.empty()) return 0.0;//tikrina ar yra pazymiu.   .empty() grazina bool tipa

    double sum = std::accumulate(mok.Pazymys.begin(), mok.Pazymys.end(), 0);
    return sum / mok.Pazymys.size();  // Use the vector size dynamically
}
std::string spacing(const std::string& name, int length) { // funkcija skirta palikti toki kieki space'u kad atrodytu tvarkingai
    int space_ammount = length - name.size();
    return std::string(space_ammount, ' ');  // grazina string tipa kuris turetu reikiama kieki space'u. cia praktiskai padaugina space kart skaiciu kuris nurodo kiek ju reikia.
}
double mediana(mokinys& mok) {
    if (mok.Pazymys.empty()) return 0.00;  //tikrina ar yra pazymiu.   .empty() grazina bool tipa

    std::sort(mok.Pazymys.begin(), mok.Pazymys.end());  //sortina pazymiu vektoriu didejimo tvarka

    int size = mok.Pazymys.size();         //jei lyginis paz skaiciu, ima dvieju viduriniu verciu vidurki
    if (size % 2 == 0) {
        return (mok.Pazymys[size / 2 - 1] + mok.Pazymys[size / 2]) / 2;
    }
    else {                                  // jei nelyginis skaicius, tai isveda vidurine verte
        return mok.Pazymys[size / 2];
    }
}
void isvedimas(std::vector<mokinys>& mok) {
    int kiekis;
    char vid_med;

    std::cout << "Iveskite kiek mokiniu noresite pamatyt" << std::endl;
    std::cin >> kiekis;

    std::cout << "Jei norite pamatyti vidurki, spauskite v, jei norite pamatyti mediana, spauskite m" << std::endl;
    std::cin >> vid_med;

    std::vector<int> numeros(kiekis);
    std::cout << "Iveskite mokiniu numerius" << std::endl;
    for (int i = 0; i < kiekis; i++) {
        std::cin >> numeros[i];
    }

    if (vid_med == 'v') {
        std::cout << "Mokinio vardas       Mokinio pavarde       Galutinis (Vid.)" << std::endl;
        std::cout << "-----------------------------------------------------------" << std::endl;
        for (int i = 0; i < kiekis; i++) {
            int idx = numeros[i] - 1;  // Adjust for zero-based indexing
            std::cout << mok[idx].Vardas << spacing(mok[idx].Vardas, 21)
                << mok[idx].Pavarde << spacing(mok[idx].Pavarde, 22)
                << std::fixed << std::setprecision(2) << vidurkis(mok[idx]) << std::endl;
        }
    }
    else {
        std::cout << "Mokinio vardas       Mokinio pavarde       Mediana" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        for (int i = 0; i < kiekis; i++) {
            int idx = numeros[i] - 1;  // Adjust for zero-based indexing
            std::cout << mok[idx].Vardas << spacing(mok[idx].Vardas, 21)
                << mok[idx].Pavarde << spacing(mok[idx].Pavarde, 22)
                << std::fixed << std::setprecision(2) << mediana(mok[idx]) << std::endl;
        }
    }
}
void generavimas(int mok_kiekis, int ND_kiekis) {
    std::ofstream df("kursiokai.txt");
    df << "Vardas                   Pavarde                    ";
    for (int i = 1; i <= ND_kiekis; i++) {
        std::string Hnd = "ND" + std::to_string(i) ;
        df << Hnd + spacing(Hnd, 11);
    }
    df << std::endl;


    for (int i = 1; i <= mok_kiekis; i++) {
        std::string tempV = "Vardas" + std::to_string(i);
        df << tempV << spacing(tempV, 25);

        std::string tempP = "Pavarde" + std::to_string(i);
        df << tempP << spacing(tempP, 28);
        for (int j = 1; j <= ND_kiekis; j++) {
            int tempND = rand() % 11;
            if (tempND == 10) df << tempND << spacing(std::to_string(tempND), 11);
            df  << tempND << spacing(std::to_string(tempND), 11);

        }
        df << std::endl;
    }
df.close();
}
