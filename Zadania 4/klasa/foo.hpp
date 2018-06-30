#ifndef FOO_HPP
#define FOO_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

class brakKlucza: public std::exception
{
};

struct para
{
        std::string napis_;
        double liczba_;

        para(std::string napis, double liczba=0.0);
};

class foo
{
    private:
        std::vector<para> foo_;

    public:
        void dodajPare(para p);
        double operator()(std::string napis) const;
};

#endif // FOO_HPP
