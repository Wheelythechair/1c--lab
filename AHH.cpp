#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <numeric>   //accumulate

#include "H.h"


std::string spacing(const std::string& name, int length) { // funkcija skirta palikti toki kieki space'u kad atrodytu tvarkingai
    int space_ammount = length - name.size();
    return std::string(space_ammount, ' ');  // grazina string tipa kuris turetu reikiama kieki space'u. cia praktiskai padaugina space kart skaiciu kuris nurodo kiek ju reikia.
}