#ifndef NOTOWANIA_HPP
#define NOTOWANIA_HPP

#include <vector>
#include <iostream>


struct para
{
        std::string napis_;
        double wartosc_;

        para(std::string napis, double wartosc = 0.0);
};

class notowania
{
    private:
        std::vector<para> notowania_;

    public:
        void pop_back(para p);
        double wartosc(std::string napis) const;
        int size() const;
        bool empty() const;
        para operator[](int indeks) const;
        para operator[](int& indeks);
};

#endif // NOTOWANIA_H
