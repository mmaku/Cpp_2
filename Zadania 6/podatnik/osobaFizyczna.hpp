#ifndef OSOBA_FIZYCZNA_H_INCLUDED
#define OSOBA_FIZYCZNA_H_INCLUDED

#include <string>
#include "pesel.hpp"
#include "data.hpp"
#include "podatnik.hpp"

class OsobaFizyczna
    : public Podatnik
{
    private:
        std::string imie_;
        std::string nazwisko_;
        PESEL pesel_;
        Data data_urodzenia_;

    public:
        OsobaFizyczna(std::string imie, std::string nazwisko, std::string pesel, int dzien, int miesiac, int rok);
        std::string Dane() override final;
};

#endif // OSOBA_FIZYCZNA_H_INCLUDED
