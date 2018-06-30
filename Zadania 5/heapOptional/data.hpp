#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <cassert>
#include <iostream>
#include <vector>

class zlyROK: public std::exception
{
};

class zlyMIESIAC: public std::exception
{
};

class zlyDZIEN: public std::exception
{
};

class Data
{
    private:
        auto Sensowna(int dzien, int miesiac, int rok) -> void;
        int rok_;
        int miesiac_;
        int dzien_;
        bool zlyR_;
        bool zlyM_;
        bool zlyD_;

    public:
        Data();
        Data(int dzien, int miesiac, int rok);
        auto Przestepny(int rok) -> bool;
        auto Rok() -> int const;
        auto Miesiac() -> int const;
        auto Dzien() -> int const;
        auto zlyR() -> bool const;
        auto zlyM() -> bool const;
        auto zlyD() -> bool const;

};

std::istream& operator>>(std::istream& we, Data &D);
Data pobieranieData(std::string polecenie);

#endif // DATA_HPP_INCLUDED
