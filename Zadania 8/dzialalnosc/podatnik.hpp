#ifndef PODATNIK_HPP_INCLUDED
#define PODATNIK_HPP_INCLUDED

#include "nip.hpp"

class Podatnik
{
    private:
        NIP nip_;

    public:
        Podatnik(std::string nip)
            : nip_(nip)
            {
            }

        virtual ~Podatnik(void) = 0;

        auto Nip(void) const -> std::string
        {
            return nip_.Napis();
        }

        virtual auto Wizytowka(void) const -> void
        {
            std::cout << "NIP: " << nip_.Napis() << '\n';
        }
};

Podatnik::~Podatnik(void) = default;

#endif // PODATNIK_HPP_INCLUDED
