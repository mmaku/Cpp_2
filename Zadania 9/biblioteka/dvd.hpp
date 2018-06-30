#ifndef DVD_HPP_INCLUDED
#define DVD_HPP_INCLUDED

#include <vector>
#include "obiekt.hpp"
#include "osoba.hpp"

class Dvd
    : public Obiekt
{
    private:
        Osoba rezyser_;
        std::vector<Osoba> obsada_;

    public:
        Dvd(std::string bio, std::string tytul, Osoba rezyser, std::vector<Osoba> obsada) // domyslne wartosci?
          : Obiekt(bio, tytul), rezyser_(rezyser), obsada_(obsada)
        {
        }

        auto Rezyser() -> Osoba const
        {
            return rezyser_;
        }

        auto Obsada() -> std::vector<Osoba> const
        {
            return obasada_;
        }
};
#endif // DVD_HPP_INCLUDED
