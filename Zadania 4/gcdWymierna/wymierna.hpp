#ifndef WYMIERNA_HPP
#define WYMIERNA_HPP

#include "GCD.hpp"


class Wymierna
{
    private:
        long licznik_;
        long mianownik_;

    public:
        Wymierna(long licznik, long mianownik);
        inline long Licznik() const
        {
            return licznik_;
        }
        inline long Mianownik() const
        {
            return mianownik_;
        }
};

auto test_Wymierna() -> void;


#endif // WYMIERNA_HPP
