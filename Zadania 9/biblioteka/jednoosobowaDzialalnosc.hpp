#ifndef JEDNOOSOBOWADZIALALNOSC_HPP_INCLUDED
#define JEDNOOSOBOWADZIALALNOSC_HPP_INCLUDED

#include "dzialalnosc.hpp"
#include "osoba.hpp"

class DzialalnoscJednoosobowa
    : public Osoba, public Dzialalnosc
{
    public:
        DzialalnoscJednoosobowa(std::string imie,
                                std::string nazwisko, std::string nip, std::string regon)
            : Osoba(imie, nazwisko), Dzialalnosc(nip, regon)
        {
        }

        auto Wizytowka(void) const -> void override
        {
            std::cout << "Imie i nazwisko: " << ImieNazwisko()
                      << " NIP: " << Nip() << " REGON: " << Regon() << '\n';
        }
};

#endif // JEDNOOSOBOWADZIALALNOSC_HPP_INCLUDED
