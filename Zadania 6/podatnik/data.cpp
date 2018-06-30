#include "data.hpp"

bool Przestepny(int rok)
{
    rok = abs(rok);
    return((rok%4 == 0 && rok%100 != 0) || rok%400 == 0);
}

bool Sensowna(int dzien, int miesiac, int rok)
{
    bool kontrola = false;

    if (0 <= rok)
    {

        if(1 <= miesiac && miesiac <= 12)
        {

            if(miesiac == 2)
            {
                if(Przestepny(rok) && 1 <= dzien && dzien <= 29) kontrola = true;
                if(!Przestepny(rok) && 1 <= dzien && dzien <= 28) kontrola = true;
            }
            else if(((miesiac % 2 == 1 && miesiac <= 7)
                    || (miesiac % 2 == 0 && miesiac >= 8))
                    && (1 <= dzien && dzien <= 31))
                        kontrola = true;
            else if(1 <= dzien && dzien <= 31) kontrola = true;
    }    }

    return kontrola;
}

std::string Data::nazywajMiesiac() const
{
    std::string wyjscie;
    switch(miesiac_)
    {
        case 1: wyjscie = " stycznia "; break;
        case 2: wyjscie = " lutego "; break;
        case 3: wyjscie = " marca "; break;
        case 4: wyjscie = " kwietnia "; break;
        case 5: wyjscie = " maja "; break;
        case 6: wyjscie = " czerwca "; break;
        case 7: wyjscie = " lipca "; break;
        case 8: wyjscie = " sierpnia "; break;
        case 9: wyjscie = " września "; break;
        case 10: wyjscie = " października "; break;
        case 11: wyjscie = " listopada "; break;
        case 12: wyjscie = " grudnia "; break;
        default: wyjscie = std::to_string(miesiac_); break;
    }
    return(wyjscie);
}

Data::Data(int dzien, int miesiac, int rok)
{
    dzien_ = dzien;
    miesiac_ = miesiac;
    rok_ = rok;

    poprawna_ = Sensowna(dzien, miesiac, rok);
}

int Data::Dzien() const
{
    return dzien_;
}

int Data::Miesiac() const
{
    return miesiac_;
}

int Data::Rok() const
{
    return rok_;
}

bool Data::Poprawna() const
{
    return poprawna_;
}

std::string Data::Wypisz() const
{
    return(std::to_string(dzien_) + nazywajMiesiac() + std::to_string(rok_) + "r.");
}

bool operator==(const Data& D1, const Data& D2)
{
    return (D1.Dzien() == D2.Dzien() && D1.Miesiac() == D2.Miesiac() && D1.Rok() == D2.Rok());
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

    while (!strumien)
    {
        strumien.ignore(1000, '\n');
        strumien.clear();
        std::cerr << "Coś poszło nie tak, podaj date jeszcze raz (format DD MM YYYY): ";
        std::cin.clear();
        std::getline(std::cin, wejscie);
        strumien.str (wejscie);
        strumien >> std::skipws >> wyjscie;
    }

    if(!wyjscie.Poprawna())
        std::cerr << "Alert: Data nie jest poprawna!'n";

    return(wyjscie);
}
