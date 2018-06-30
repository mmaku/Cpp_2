#ifndef OSOBAFIZYCZNA_HPP_INCLUDED
#define OSOBAFIZYCZNA_HPP_INCLUDED

#include "podatnik.hpp"
#include "osoba.hpp"

class OsobaFizyczna
    : public Podatnik, public Osoba
{
    public:
        OsobaFizyczna(std::string imie, std::string nazwisko, std::string nip)
            : Podatnik(nip), Osoba(imie, nazwisko)
        {
        }

        auto Wizytowka(void) const -> void override
        {
            std::cout << "Imie i nazwisko: " ImieNazwisko() << " NIP: " << nip_.napis() '\n';
        }
};

#endif // OSOBAFIZYCZNA_HPP_INCLUDED
