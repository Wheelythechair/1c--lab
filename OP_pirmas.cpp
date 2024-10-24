#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <numeric>   //accumulate
#include <typeinfo>
#include <chrono>

#include "H.h"




struct mokinys {
    std::string Vardas, Pavarde;
    std::vector<int> Pazymys;
    int Egz;
    double galutinis;
};




int failo_ilgis();
void nuskaitymas(std::vector<mokinys>& mok, int ilgis, int ND_kiekis, std::string failas);
void space_remove(mokinys& mok);
double vidurkis(const mokinys& mok);
double mediana(mokinys& mok);
void isvedimas(std::vector<mokinys>& mok);
void generavimas(int mok_kiekis, int ND_kiekis, std::string pavadinimas);
void pav_gen(int kiekis, std::vector<std ::string>& pavadinimai);
void f_trinimas(std::vector<std::string>& pavadinimai);
void gal_isvedimas(std::vector<mokinys>& gal_mok);
void isskirstymas(std::vector<mokinys>& pavadinimas, int mok_kiekis);







int main() {
    std::ofstream df1("Saunuoliai.txt");    //isvalo failus
    std::ofstream df2("begedziai.txt");
    df1.close();
    df2.close();

    int ilgis, ND_kiekis, mok_kiekis, f_kiekis, v2mok_kiekis, v2ND_kiekis;
    char gen, test, test1, test2;
    std::vector<mokinys> mok, gen_mok;
    std::vector < std::vector<mokinys >> mok_failai;
    std::vector<std::string> pavadinimai;
    std::string f_pavadinimas;

    
    std::cout << "ar norime sugeneruot sabloninius failus v0.2 versijai? t - generuosime, n - ne" << std::endl; // jei norim sukuriam sabloninius failus norimo dydzio mok kiekio ir nd kiekio
    std::cin >> test;
    if (test == 't') {
        std::cout << "programos versijai v0.2 sugeneruokime sabloniniu failu. Kiek failu kursime?" << std::endl;
        std::cin >> f_kiekis;
        pav_gen(f_kiekis, pavadinimai);
        for (int i = 0; i < f_kiekis; i++) {
            std::cout << "kiek mokiniu noretumet sugeneruot ir kiek pazymiu jie gavo?" << std::endl;
            std::cin >> v2mok_kiekis >> v2ND_kiekis;
            generavimas(v2mok_kiekis, v2ND_kiekis, pavadinimai[i]);         //generuoju nurodyta kieki failu su nurodytais kiekiais mokiniu ir pazymiu
        }
        std::cout << "ar noretumet suskirstyt mokiniusi ir gauti ju rezultatus? t - taip, n - ne" << std::endl;
        std::cin >> test2;
        if (test2 == 't') {
            while (true) {
                std::cout << "Prasom pasirinkti is siu failu: " << std::endl;
                for (int i = 0; i < pavadinimai.size(); i++) std::cout << pavadinimai[i] << std::endl;
                std::cin >> f_pavadinimas;

                if (std::find(pavadinimai.begin(), pavadinimai.end(), f_pavadinimas) != pavadinimai.end()) {
                    std::cout << "aciu" << std::endl;

                    break;
                }
            }
            
            nuskaitymas(gen_mok, v2mok_kiekis, v2ND_kiekis, f_pavadinimas);
            gal_isvedimas(gen_mok);
            isskirstymas(gen_mok, v2mok_kiekis);
        }
    }
    












    std::cout << "Ar norite istrinti visus v0.2 sugeneruotus failus? t - istrinti, n - ne" << std::endl; // naudotojui norint, trinami visi failai
    std::cin >> test1;
    if (test1 == 't') f_trinimas(pavadinimai);

    //////////////////////////////////////////////////////////////////////////////////////////
    std:: cout << "ar norite sugeneruot faila? Spauskite t, jei taip, n, jei ne" << std::endl;
    std::cin >> gen;
    if (gen == 't') {
        std::cout << "kiek mokiniu noretumet sugeneruot ir kiek pazymiu jie gavo?" << std::endl;
        std::cin >> mok_kiekis >> ND_kiekis;
        generavimas(mok_kiekis, ND_kiekis, "kursiokai.txt");
        nuskaitymas(mok, failo_ilgis(), ND_kiekis, "kursiokai.txt");      // vykdau nuskaitymo funkcija
    }
    else {
        while (true) {
            try {           //tikrinu ar ivestas skaicius
                std::cout << "Kiek ND buvo uzduota?" << std::endl;
                std::cin >> ND_kiekis;
                if (std::cin.fail()) {          //jei ivesta verte neatitinka is anksto nustatyto kintamojo duomenu tipo, isijungia if funkcija

                    std::cin.clear();           // si eilute istrina errora kylanti is neteisingos vertes ivedimo
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         // ivesta verte istrinama
                    throw 500;
                }
                break;          // jei verte teisinga, tai ciklas nutraukiamas ir programa gali testis
            }
            catch (int a) {
                std::cout << "Prasau iveskite skaiciu. Bandom vel" << std::endl;        // ismetama zinute, jog ivestas ne skaicius
            }
        }


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
void nuskaitymas(std::vector<mokinys>& strukturos_pav, int ilgis, int ND_kiekis, std::string failas) { // funkcijoj sukuriu nauja mokinys struktura ir nuskaicius viska, graziai viska imetu i mokinys mok struktura

    
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
        df >> current.Egz;
        current.galutinis = galutinis(vidurkis(current), current.Egz);          // priskiriu galutinio balo verte
        std::getline(df, temp);  // praleidziu likusia eilute
        strukturos_pav.push_back(current);
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

    
    while (true){
        try {
            std::cout << "Iveskite kiek mokiniu noresite pamatyt" << std::endl;
            std::cin >> kiekis;
            if (std::cin.fail()) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw 500;
            }
                break;
        }
        catch (int a) {
            std::cout << "Prasau iveskite skaiciu. Bandom vel" << std::endl;
        }
    }
    

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
            int idx = numeros[i] - 1;
            std::cout << mok[idx].Vardas << spacing(mok[idx].Vardas, 21)
                << mok[idx].Pavarde << spacing(mok[idx].Pavarde, 22)
                << std::fixed << std::setprecision(2) << vidurkis(mok[idx]) << std::endl;
        }
    }
    else {
        std::cout << "Mokinio vardas       Mokinio pavarde       Mediana" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        for (int i = 0; i < kiekis; i++) {
            int idx = numeros[i] - 1;
            std::cout << mok[idx].Vardas << spacing(mok[idx].Vardas, 21)
                << mok[idx].Pavarde << spacing(mok[idx].Pavarde, 22)
                << std::fixed << std::setprecision(2) << mediana(mok[idx]) << std::endl;
        }
    }
}
void generavimas(int mok_kiekis, int ND_kiekis, std:: string pavadinimas) {
    auto pradzia = std::chrono::high_resolution_clock::now();       //pradedu matuot laika
    
    std::ofstream df(pavadinimas);
    df << "Vardas                   Pavarde                    ";       // i antraste(pirma eilute) ivedu varda ir pavarde
    for (int i = 1; i <= ND_kiekis; i++) {
        std::string Hnd = "ND" + std::to_string(i);     //ta pati darau su ND
        df << Hnd + spacing(Hnd, 11);
    }
    df << "Egz.";
    df << std::endl;


    for (int i = 1; i <= mok_kiekis; i++) {     //irasau vardo ir pavardes sablona
        std::string tempV = "Vardas" + std::to_string(i);
        df << tempV << spacing(tempV, 25);

        std::string tempP = "Pavarde" + std::to_string(i);
        df << tempP << spacing(tempP, 28);
        for (int j = 1; j <= ND_kiekis + 1; j++) {  // kiekvienam mokiniui irasau is anksto nustatyta, atsitiktini nd pazymi + egz.
            int tempND;
            while (true) {
                tempND = rand() % 11;
                if (tempND != 0) {
                    break;              // kadangi mokytojai dazniausiai neskiria 0 kaip ivertinimo, tai gavus atsitiktini nulio ivertinima, bandom vel
                }
            }

            if (tempND == 10) {
                df << tempND << spacing(std::to_string(tempND), 11);        // palaikau tvarkinga space kieki gavus desimtuka
            }
            else {
                df << tempND << spacing(std::to_string(tempND), 11);
            }
        }
        df << std::endl;
    }
    df.close();


    auto pabaiga = std::chrono::high_resolution_clock::now();

    auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga - pradzia);



    std::cout << "Kurti faila programa uztruko: " << laikas.count() << " ms" << std::endl;
    std::cout << std::endl;

}
void pav_gen(int kiekis, std::vector<std::string>& pavadinimai) {
    for (int i = 1; i <= kiekis; i++) {
        std::string temp;
        temp = "pavadinimas" + std::to_string(i) + ".txt";
        pavadinimai.push_back(temp);
    }
}
void f_trinimas(std::vector<std::string>& pavadinimai) {
    for (int i = 0; i < pavadinimai.size(); i++) {
        remove(pavadinimai[i].c_str());     //kadangi komanda "remove" reikalauja char tipo, tai pradzioj mano string tipo kintamaji pavadinimai, verciu i char array
    }
}
void gal_isvedimas(std::vector<mokinys>& gal_mok) { //tiesiog isveda varda, pavarde, galutini pazymi ir pavadinima saunuoliai/begedziai
    int kiekis;
    char vid_med;

    for (auto& m : gal_mok) {       //panaikina visus nuskaitytus tarpus, nes veliau galetu kilt prblemu su spacing funkcija
        space_remove(m);
    }


    while (true) {
        try {
            std::cout << "Iveskite kiek mokiniu noresite pamatyt" << std::endl;
            std::cin >> kiekis;
            if (std::cin.fail()) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw 500;
            }
            break;
        }
        catch (int a) {
            std::cout << "Prasau iveskite skaiciu. Bandom vel" << std::endl;
        }
    }

    std::vector<int> numeros(kiekis);
    std::cout << "Iveskite mokiniu numerius" << std::endl;
    for (int i = 0; i < kiekis; i++) {
        std::cin >> numeros[i];
    }

        std::cout << "Mokinio vardas       Mokinio pavarde       Galutinis pazymys         Vadiname" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
        for (int i = 0; i < kiekis; i++) {
            int idx = numeros[i] - 1;
            std::cout << gal_mok[idx].Vardas << spacing(gal_mok[idx].Vardas, 21);
            std::cout << gal_mok[idx].Pavarde << spacing(gal_mok[idx].Pavarde, 29);
            std::cout << std::fixed << std::setprecision(2) << gal_mok[idx].galutinis << spacing(std:: to_string(gal_mok[idx].galutinis), 23);
            std::cout << vadinam(gal_mok[idx].galutinis) << std::endl;
        }
}
void isskirstymas(std::vector<mokinys>& pavadinimas, int mok_kiekis) {      //atidaro failus ir jei galutinis balas nemazesnis uz 5, iraso mokini i saunuoliai.txt
    std::ofstream df1("Saunuoliai.txt");
    std::ofstream df2("begedziai.txt");

    df1 << "Mokinio vardas       Mokinio pavarde       Galutinis pazymys         Vadiname" << std::endl;
    df1 << "-----------------------------------------------------------------------------" << std::endl;
    df2 << "Mokinio vardas       Mokinio pavarde       Galutinis pazymys         Vadiname" << std::endl;
    df2 << "-----------------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < mok_kiekis; i++) {
        if (pavadinimas[i].galutinis >= 5.0) {
            df1 << pavadinimas[i].Vardas << spacing(pavadinimas[i].Vardas, 21)
                << pavadinimas[i].Pavarde << spacing(pavadinimas[i].Pavarde, 30)
                << std::fixed << std::setprecision(2) << pavadinimas[i].galutinis << spacing(std::to_string(pavadinimas[i].galutinis), 19)
                << vadinam(pavadinimas[i].galutinis) << std::endl;
        }
        else {
            df2 << pavadinimas[i].Vardas << spacing(pavadinimas[i].Vardas, 21)
                << pavadinimas[i].Pavarde << spacing(pavadinimas[i].Pavarde, 30)
                << std::fixed << std::setprecision(2) << pavadinimas[i].galutinis << spacing(std::to_string(pavadinimas[i].galutinis), 19)
                << vadinam(pavadinimas[i].galutinis) << std::endl;
        }
    }

    df1.close();
    df2.close();

}