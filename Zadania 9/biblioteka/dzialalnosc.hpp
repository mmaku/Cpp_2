#ifndef DZIALALNOSC_HPP_INCLUDED
#define DZIALALNOSC_HPP_INCLUDED

#include "podatnik.hpp"

class Dzialalnosc
    : public Podatnik
{
    private:
        std::string regon_;

    public:
        Dzialalnosc(std::string nip, std::string regon)
            : Podatnik(nip), regon_(regon)
        {
        }

        auto Regon(void) const -> std::string
        {
            return regon_;
        }

        auto Wizytowka(void) const -> void override
        {
            std::cout << "NIP: " << Nip() << " REGON: " << Regon() << '\n';
        }
};

#endif // DZIALALNOSC_HPP_INCLUDED
