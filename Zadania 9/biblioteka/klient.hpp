#ifndef PODATNIK_HPP_INCLUDED
#define PODATNIK_HPP_INCLUDED

#include <string>
#include "bik.hpp"

class Klient
{
    private:
        BIK bik_; // biblioteczna identyfikacja klienta

    public:
        Klient(std::string bik)
            : bik_(bik)
            {
            }

        virtual ~Klient() = 0;

        auto napisBIK() -> std::string const
        {
            return bik_.Napis();
        }

        virtual auto Wizytowka() -> std::string const
        {
            return "BIK: " + bik_.Napis();
        }
};

Klient::~Klient(void) = default;

#endif // PODATNIK_HPP_INCLUDED
