#include "punkt.hpp"
#include "prosta.hpp"

#include <iostream>
#include <cassert>
#include <cmath>

Prosta::Prosta(Punkt p1, Punkt p2)
{
    assert(p1.X()!=p2.X() || p1.Y()!=p2.Y());
    if(p1.X()==p2.X())
    {
        a_=1;
        b_=0;
        c_=-p1.X();
    }
    else
    {
        a_=p2.Y()-p1.Y();
        b_=p1.X()-p2.Y();
        c_=p1.Y()*p2.X()-p2.Y()*p1.Y();
    }
}
double Prosta::wspolczynnik() const
{
    if(b_==0)
        return 0;
    else
        return -a_/b_;
}
double Prosta::przesuniecie() const
{
    if(b_==0)
        return -c_;
    else
        return -c_/b_;
}

void test_prosta()
{
    Punkt p1(1.0,1.0);
    Punkt p2(-1.0,-1.0);
    Punkt p3(2.0,1.0);
    Punkt p4(-2.0,1.0);

    Prosta P1(p1,p2);
    Prosta P2(p3,p4);

    assert(P1.wspolczynnik()==1.0);
    assert(P1.przesuniecie()==0.0);

    assert(P2.wspolczynnik()==0.0);
    std::cerr << P2.przesuniecie();
    assert(P2.przesuniecie()==3.0);

    std::cerr << "testProsta ok\n";
}
