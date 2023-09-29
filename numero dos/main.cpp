#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iomanip>

struct mokinys {
  std :: string Vardas, Pavarde;
  int Pazymys[17];
};



int failo_ilgis();
void nuskaitymas(std::vector<mokinys>& mok, int ilgis);
void space_remove(mokinys& mok);
double vidurkis(std::vector<mokinys>& mok, int mok_nr);
std :: string spacing(std :: string name, int length);

void isvedimas(std::vector<mokinys>& mok);


int main() 
{
int ilgis;
std::vector<mokinys> mok;

ilgis = failo_ilgis();      // skaiciuoju kiek naudojamu eiluciu yra faile
nuskaitymas(mok, ilgis);      // vykdau nuskaitymo funkcija
for (auto& m:mok){
space_remove(m);
}
//spacing("vardas1", 21);
//std :: cout << std::fixed << std ::setprecision(2) << vidurkis(mok, 1); 
isvedimas(mok);
  
//std :: cout << ilgis;
//std::cout<< mok[9999].Pavarde << mok[1].Vardas << " " << mok[1].Pazymys[16] << " " << mok[1].Pazymys[15] <<  std::endl;
//std :: cout << mok[1].Vardas << std :: endl;


return 0;
}



int failo_ilgis(){
  std :: string temp;
  int x = 0;
  
  std :: ifstream df ("ND.txt");

  
  while (std::getline(df, temp)){      // kol faile yra eilute, tol didinu x, kad surasciau failo eiluciu skaiciu
    x++;
  }
  x = x - 1;      // atimu nes pirma eilute mums nereikalinga
  df.close();
  return x;
}
void nuskaitymas(std::vector<mokinys>& mok, int ilgis){
std :: string temp;          // string temp naudosiu kad pereiciau i kita eilute nes nesugalvojau efektyvesnio budo :p
char raid[50];          // sita char naudosiu kad priskirt vardui ir pavardei reiksmes veliau
int idiot_space;
  
std :: ifstream df ("ND.txt");        // atidaro faila

std::getline(df, temp);                // praleidziu 1 eilute, nes jis neturi man reikalingu duomenu
  
for (int i=1; i<= ilgis; i++){        // ciklas skirtas nuskaityti ir priskirti vienos failo eilues duomenis
  mokinys current;
  
  df.get(raid, 20);        // skaito varda
  current.Vardas = raid;
  df.get(raid, 26);        // skaito pavarde
  current.Pavarde = raid; 
  
  for (int j=1; j<=16; j++){       // antras ciklas tam, nes turiu daug pazymiu kuriuos patogiausia tureti masyve
    df >> current.Pazymys[j];      // priskiria pazymius
  }
  std :: getline (df, temp);          // turbut yra geresnis budas taip padaryt bet sita eilute priskiria nenaudojamam kintamajam likusios eilutes simbolius tam kad kitoj ciklo iteracijoj pradetu skaityti is eilutes pradzios
  mok.push_back(current);
}
df.close();        // uzdarau faila
}
void space_remove(mokinys& mok){
    mok.Vardas.erase(std::remove_if(mok.Vardas.begin(), mok.Vardas.end(), ::isspace), mok.Vardas.end());    // .erase yra skirtas istrinti white space *#* naudojamas .erase(starting pos, ending pos) *#*, remove_if perkelia visus non-space simbolius i prieki ir pradine pos paima white space pradzia, o galutine pos parenka kaip paskutini white sapce, kuris ir yra paskutinis simbolis stringe.
    mok.Pavarde.erase(std::remove_if(mok.Pavarde.begin(), mok.Pavarde.end(), ::isspace), mok.Pavarde.end());
}
double vidurkis(std::vector<mokinys>& mok, int mok_nr){
  double vidurkis = 0.0;
    for (int i=1; i<= 16; i++){
    vidurkis = vidurkis + mok[mok_nr].Pazymys[i];
  }
  return vidurkis / 16;
}
std :: string spacing(std :: string name, int length){
  int space_ammount;
  std :: string space = "";
  space_ammount = length - name.size();
  for (int i=0; i<space_ammount; i++){
     space += " ";
  }

  return space;
}

void isvedimas(std::vector<mokinys>& mok){
int kiekis;
  
std :: cout << "Iveskite kiek mokiniu noresite pamatyt" << std :: endl;
std :: cin >> kiekis;

int numeros[kiekis];
  
std :: cout << "Iveskite mokinio numerius" << std :: endl;
for (int i=0; i < kiekis; i++){
  std :: cin >> numeros[i];
}
std :: cout << "Mokinio vardas       Mokinio pavarde       Galutinis (Vid.)" << std :: endl;
std :: cout << "-----------------------------------------------------------" << std :: endl;
for (int i=0; i< kiekis; i++){
  std :: cout << mok[numeros[i]-1].Vardas << spacing(mok[numeros[i]-1].Vardas, 21) << mok[numeros[i]-1].Pavarde << spacing(mok[numeros[i]-1].Pavarde, 22) ;
std :: cout << std::fixed << std ::setprecision(2) << vidurkis(mok, numeros[i]-1) << std :: endl;
}
    
}

