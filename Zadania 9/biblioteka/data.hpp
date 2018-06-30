#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

bool Sensowna(int dzien, int miesiac, int rok);
bool Przestepny(int rok);

class Data
{
    private:
        int rok_;
        int miesiac_;
        int dzien_;
        bool przestepny_;
        bool poprawna_ = true;

        auto nazywajMiesiac() -> std::string const;

    public:
    //    Data();
        Data(int dzien, int miesiac, int rok);
        auto Dzien() -> int const;
        auto Miesiac() -> int const;
        auto Rok() -> int const;
        auto Poprawna()-> bool const;
        auto Wypisz() -> std::string const;
        auto operator<(Data D) -> bool const;
};

auto operator==(const Data& D1, const Data& D2) -> bool;

#endif // DATA_HPP_INCLUDED
