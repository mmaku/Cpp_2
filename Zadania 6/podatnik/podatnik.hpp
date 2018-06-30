#ifndef PODATNIK_H_INCLUDED
#define PODATNIK_H_INCLUDED

#include <string>
#include "konwersja.hpp"

class Podatnik
{
    public:
       // virtual void Podatnik() = 0; // tzw. metoda czysto wirtualna, ale cpp nie wspiera virtualnych konstruktorów
        virtual ~Podatnik()
        {}; // zgodnie z poleceniem

        virtual std::string Dane() = 0;


};

#endif // PODATNIK_H_ INCLUDED
