#ifndef PROSTA_HPP
#define PROSTA_HPP

#include "punkt.hpp"

class Prosta
{
    private:
        double a_;
        double b_;
        double c_;   //ax+by+c=0

    public:
        Prosta(Punkt p1, Punkt p2);
        double wspolczynnik() const;
        double przesuniecie() const;
};

void test_prosta();

#endif // PROSTA_HPP
