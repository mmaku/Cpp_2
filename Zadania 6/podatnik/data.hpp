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

        std::string nazywajMiesiac() const;

    public:
    //    Data();
        Data(int dzien, int miesiac, int rok);
        int Dzien() const;
        int Miesiac() const;
        int Rok() const;
        bool Poprawna() const;
        std::string Wypisz() const;
    //    bool operator<(Data a) const;
};

////////////////////////////////////////////////////////////////////TESTY/////////////////////////////////////////////////////////////////////////////

bool operator==(const Data& D1, const Data& D2);
std::istream& operator>>(std::istream& we, Data &D);
Data pobieranieData(std::string polecenie);

#endif // DATA_HPP_INCLUDED
