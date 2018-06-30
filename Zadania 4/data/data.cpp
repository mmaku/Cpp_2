#include <iostream>
#include <sstream>
#include <assert.h>

#include <sstream>
#include "data.hpp"



auto Data::Sensowna(int dzien, int miesiac, int rok) -> void
{
    bool kontrolaROK = false;
    bool kontrolaMIESIAC = false;
    bool kontrolaDZIEN = false;

    if (0 <= rok)
    {
        kontrolaROK = true;
    }

    if(1 <= miesiac && miesiac <= 12)
    {
        kontrolaMIESIAC = true;
    }

    if(miesiac == 2)
    {
        if(Przestepny(rok) && 1 <= dzien && dzien <= 29) kontrolaDZIEN = true;
        if(!Przestepny(rok) && 1 <= dzien && dzien <= 28) kontrolaDZIEN = true;
    }
    else if(((miesiac % 2 == 1 && miesiac <= 7)
            || (miesiac % 2 == 0 && miesiac >= 8))
            && (1 <= dzien && dzien <= 31))
                kontrolaDZIEN = true;
    else if(1 <= dzien && dzien <= 31) kontrolaDZIEN = true;

    if(!kontrolaDZIEN)
        throw zlyDZIEN{};
    if(!kontrolaMIESIAC)
        throw zlyMIESIAC{};
    if(!kontrolaROK)
        throw zlyROK{};
}


auto Data::Dzien() -> int const
{
    return dzien_;
}

auto Data::Miesiac() -> int const
{
    return miesiac_;
}

auto Data::Rok() -> int const
{
    return rok_;
}

auto Data::zlyD() -> bool const
{
    return zlyD_;
}

auto Data::zlyM() -> bool const
{
    return zlyM_;
}

auto Data::zlyR() -> bool const
{
    return zlyR_;
}


auto Data::Przestepny(int rok) -> bool
{
    rok = abs(rok);
    return((rok%4 == 0 && rok%100 != 0) || rok%400 == 0);
}

Data::Data()
{
    rok_ = miesiac_ = dzien_ = 1;
}

Data::Data(int dzien, int miesiac, int rok)
{
    zlyD_ = false;
    zlyM_ = false;
    zlyR_ = false;


    try
    {
    dzien_ = dzien;
    miesiac_ = miesiac;
    rok_ = rok;

    Sensowna(dzien, miesiac, rok);
    }

    catch(zlyDZIEN& zd)
    {
       zlyD_ = true;
    }
    catch(zlyMIESIAC& zm)
    {
        zlyM_ = true;
    }
    catch(zlyROK& zr)
    {
        zlyR_ = true;
    }
}

std::istream& operator>>(std::istream& we, Data &D)
{
    int dzien, miesiac, rok;
    we >> dzien >> miesiac >> rok;
    if (we)
    {
        D = Data(dzien, miesiac, rok);
    }
    else
        we.setstate(std::ios_base::failbit);
    return we;
}

Data pobieranieData(std::string polecenie)
{
    std::string wejscie;
    Data wyjscie(1, 1, 1);

    std::cout << polecenie;
    std::getline(std::cin, wejscie);
    std::istringstream strumien(wejscie);
    strumien >> std::skipws >> wyjscie;

  //  while (!strumien || wyjscie.zlyR() || wyjscie.zlyM() || wyjscie.zlyD())
    while (!strumien)
    {
        strumien.ignore(1000, '\n');
        strumien.clear();
        std::cout << "Coś poszło nie tak, podaj date jeszcze raz (format DD MM YYYY): ";
        std::cin.clear();
        std::getline(std::cin, wejscie);
        strumien.str (wejscie);
        strumien >> std::skipws >> wyjscie;
    }

    return(wyjscie);
}
