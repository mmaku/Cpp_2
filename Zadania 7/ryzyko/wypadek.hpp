#ifndef WYPADEK_HPP_INCLUDED
#define WYPADEK_HPP_INCLUDED

#include "podryzyko.hpp"

class Wypadek
    : public Podryzyko
{
    public:
        explicit Wypadek(int wiek_wlasciciela)
            : Podryzyko(wiek_wlasciciela < 26 ? (0.2) : (0.1))
//            : Podryzyko(0.0)
        {
//            if (wiek_wlasciciela < 26)
//                stawka_ = 0.2;
//            else
//                stawka_ = 0.1;
        }
};


#endif // WYPADEK_HPP_INCLUDED
