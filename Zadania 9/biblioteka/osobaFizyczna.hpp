#ifndef OSOBAFIZYCZNA_HPP_INCLUDED
#define OSOBAFIZYCZNA_HPP_INCLUDED

#include <string>
#include "klient.hpp"
#include "osoba.hpp"

class OsobaFizyczna
    : public Klient, public Osoba
{
    public:
        OsobaFizyczna(std::string imie, std::string nazwisko, std::string bik)
            : Osoba(imie, nazwisko), Klient(bik)
        {
        }

        auto Wizytowka() const -> std::string override
        {
            return "Imie i nazwisko: " ImieNazwisko() + " BIK: " + Napis();
        }

        auto Imie() const -> std::string
        {
            return Imie();
        }

        auto Nazwisko() const -> std::string
        {
            return Nazwisko();
        }
};

#endif // OSOBAFIZYCZNA_HPP_INCLUDED
