#include "osobaFizyczna.hpp"
#include "pesel.cpp"


OsobaFizyczna::OsobaFizyczna(std::string imie, std::string nazwisko, std::string pesel,
                             int dzien, int miesiac, int rok)
    : imie_(imie), nazwisko_(nazwisko), pesel_(pesel),
      data_urodzenia_(Data(dzien, miesiac, rok))
{}

std::string OsobaFizyczna::Dane()
{
    return "<osoba " + imie_ + " " + nazwisko_ + " "  + pesel_.napis() + " " + data_urodzenia_.Wypisz() + ">";
}
