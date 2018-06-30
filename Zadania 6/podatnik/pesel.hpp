#ifndef PESEL_HPP_INCLUDED
#define PESEL_HPP_INCLUDED

#include "data.hpp"

#include <string>

bool sensownyPESEL(std::string P);


class PESEL
{
    private:
        char a_, b_, c_, d_, e_ ,f_ , g_, h_, i_, j_, k_;
        bool sensowny_ = true;

    public:
        PESEL(std::string wejscie);
        std::string napis() const;
        Data DataUrodzenia() const;
        bool czyKobieta() const;
        bool czyPoprawnaKontrolna() const;
        bool czySensowny() const;
};

////////////////////////////////////////////////////////////////////TESTY/////////////////////////////////////////////////////////////////////////////

void test_sensownyPESEL();
void test_czyPoprawny();
void test_napis();
void test_DataUrodzenia();

void testPESEL();

#endif // PESEL_HPP_INCLUDED
