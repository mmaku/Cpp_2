#include "GCD.hpp"
#include "wymierna.hpp"

#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>


Wymierna::Wymierna(long licznik = 0, long mianownik = 1)
    : licznik_(licznik), mianownik_(mianownik)
{
    assert(mianownik != 0);

    long znak = 1;
    if (licznik_ * mianownik_ < 0) znak = -1;
    licznik_ = znak * licznik / GCD(licznik, mianownik);
    mianownik_= abs(mianownik/GCD(licznik, mianownik));
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


auto test_Wymierna() -> void
{
    Wymierna w1(2,-4);

    assert(w1.Licznik()==-1);
    assert(w1.Mianownik()==2);

    Wymierna w2;
    assert(w2.Licznik()==0);
    assert(w2.Mianownik()==1);

    Wymierna w3(2);
    assert(w3.Licznik()==2);
    assert(w3.Mianownik()==1);

    w1=3;
    assert(w1.Licznik()==3);
    assert(w1.Mianownik()==1);

    std::cerr << "test_Wymierna ok\n";
}
