#include "arithm.hpp"

#include <iostream>
#include <sstream>

std::string Arithmetics(std::string text)
{
    double liczba;
    std::string wyjscie;
    std::stringstream strumien;
    strumien << text;
    strumien >> liczba;
    strumien.str(std::string());
    std::stringstream strumien1;

    strumien1 << liczba;
    strumien1 >> wyjscie;

    return wyjscie;
}
