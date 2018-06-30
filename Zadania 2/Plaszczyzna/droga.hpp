#ifndef DROGA_HPP
#define DROGA_HPP

#include "punkt.hpp"
#include <vector>

class Droga
{
    private:
        std::vector<Punkt> D_;

    public:
        void nowy_punkt(Punkt p);
        double dlugosc() const;
};

void test_droga();

#endif // DROGA_HPP
