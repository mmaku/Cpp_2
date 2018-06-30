#ifndef FIRMA_HPP_INCLUDED
#define FIRMA_HPP_INCLUDED


#include <string>
#include "klient.hpp"

class Firma
    : public Klient
{
    private:
        std::string nazwa_;

    public:
        Firma(std::string nazwa, std::string bik)
            : nazwa_(nazwa), Klient(bik)
        {
        }

        auto Wizytowka() const -> std::string override
        {
            return "Nazwa: " + nazwa_ + " BIK: " + Napis();
        }

        auto Nazwa() const -> std::string
        {
            return nazwa_;
        }
};

#endif // FIRMA_HPP_INCLUDED
