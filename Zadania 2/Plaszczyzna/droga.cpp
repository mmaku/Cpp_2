#include "punkt.hpp"
#include "droga.hpp"

#include <cmath>
#include <cassert>
#include <iostream>

void Droga::nowy_punkt(Punkt p)
{
    D_.push_back(p);
}

double Droga::dlugosc() const
{
    int d=D_.size();
    double wynik=0.0;
    if (d>=2)
    {
        for(int i=0;i<=d-2;++i)
        {
            int a = (D_[i]).X()-(D_[i+1]).X();
            int b = (D_[i]).Y()-(D_[i+1]).Y();
            wynik += sqrt(pow(a,2)+pow(b,2));
        }
    }
    return wynik;
}

void test_droga()
{
    Punkt p1(0.0,0.0);
    Punkt p2(1.0,0.0);
    Punkt p3(1.0,1.0);
    Punkt p4(2.0,1.0);

    Droga D;
    D.nowy_punkt(p1);
    D.nowy_punkt(p2);
    D.nowy_punkt(p3);
    D.nowy_punkt(p4);
    assert(D.dlugosc()==3.0); // do poprawki


    std::cerr << "testDroga ok\n";
}
