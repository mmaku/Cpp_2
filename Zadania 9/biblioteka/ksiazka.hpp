#ifndef KSIAZKA_HPP_INCLUDED
#define KSIAZKA_HPP_INCLUDED

#include <vector>
#include "obiekt.hpp"
#include "osoba.hpp"


class Ksiazka
    : public Obiekt
{
    private:
        std::vector<Osoba> autorzy_;
      //  ISBN isbn_

    public:
        Ksiazka(std::string bio, std::string tytul, std::vector<Osoba> autorzy) // domyslne wartosci?
            : Obiekt(bio, tytul), autorzy_(autorzy)
        {
        }

};


#endif // KSIAZKA_HPP_INCLUDED
