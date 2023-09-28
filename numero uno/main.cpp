#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

struct mokinys {
  std :: string Vardas, Pavarde;
  int Pazymys[16], Egz;
};

int failo_ilgis();
void nuskaitymas(mokinys mok[], int ilgis);
void space_remove(mokinys mok[], int ilgis);

int main() 
{
int ilgis;
mokinys mok[50];  //####### note: reikes daugiau ne 50 :)

ilgis = failo_ilgis();      // skaiciuoju kiek naudojamu eiluciu yra faile
nuskaitymas(mok, ilgis);      // vykdau nuskaitymo funkcija
space_remove(mok, ilgis);
  
//std :: cout << ilgis;
//std::cout<< mok[5].Vardas << mok[6].Pavarde << mok[21].Pazymys[4] << std::endl;

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
void nuskaitymas(mokinys mok[], int ilgis){
std :: string temp;          // string temp naudosiu kad pereiciau i kita eilute nes nesugalvojau efektyvesnio budo :p
char raid[50];          // sita char naudosiu kad priskirt vardui ir pavardei reiksmes veliau
  
std :: ifstream df ("ND.txt");        // atidaro faila

std::getline(df, temp);                // praleidziu 1 eilute, nes jis neturi man reikalingu duomenu
  
for (int i=1; i<= ilgis; i++){        // ciklas skirtas nuskaityti ir priskirti vienos failo eilues duomenis
  df.get(raid, 24);        // skaito varda
  mok[i].Vardas = raid;
  df.get(raid, 26);        // skaito pavarde
  mok[i].Pavarde = raid; 
  
  for (int j=1; j<=15; j++){       // antras ciklas tam, nes turiu daug pazymiu kuriuos patogiausia tureti masyve
    df >> mok[i].Pazymys[j];      // priskiria pazymius
  }
  df >> mok[i].Egz;              // priskiria egz pazymi
  std :: getline (df, temp);          // turbut yra geresnis budas taip padaryt bet sita eilute priskiria nenaudojamam kintamajam likusios eilutes simbolius tam kad kitoj ciklo iteracijoj pradetu skaityti is eilutes pradzios
}
df.close();        // uzdarau faila
}
void space_remove(mokinys mok[], int ilgis){
  for (int i=1; i<=ilgis; i++){
    mok[i].Vardas.erase(std::remove_if(mok[i].Vardas.begin(), mok[i].Vardas.end(), ::isspace), mok[i].Vardas.end());    // .erase yra skirtas istrinti white space *#* naudojamas .erase(starting pos, ending pos) *#*, remove_if perkelia visus non-space simbolius i prieki ir pradine pos paima white space pradzia, o galutine pos parenka kaip paskutini white sapce, kuris ir yra paskutinis simbolis stringe.
    mok[i].Pavarde.erase(std::remove_if(mok[i].Pavarde.begin(), mok[i].Pavarde.end(), ::isspace), mok[i].Pavarde.end());
  }
}

