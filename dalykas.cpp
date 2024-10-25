#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <numeric>   //accumulate

#include "Header.h"


std::string spacing(const std::string& name, int length) { // funkcija skirta palikti toki kieki space'u kad atrodytu tvarkingai
    int space_ammount = length - name.size();
    return std::string(space_ammount, ' ');  // grazina string tipa kuris turetu reikiama kieki space'u. cia praktiskai padaugina space kart skaiciu kuris nurodo kiek ju reikia.
}

double galutinis(double vidurkis, int egz) {
    return vidurkis * 0.4 + egz * 0.6;
}

std::string vadinam(double galutinis) {
    if (galutinis >= 5.0) return "saunuoiliai";
    else return "begedziai";
}