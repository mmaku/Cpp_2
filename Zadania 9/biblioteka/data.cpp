#include "data.hpp"

auto Przestepny(int rok) -> bool
{
    rok = abs(rok);
    return((rok%4 == 0 && rok%100 != 0) || rok%400 == 0);
}

auto Sensowna(int dzien, int miesiac, int rok) -> bool
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
        }
    }

    return kontrola;
}

auto Data::nazywajMiesiac() -> std::string const
{
    std::string wyjscie;
    switch(miesiac_)
    {
    case 1:
        wyjscie = " stycznia ";
        break;
    case 2:
        wyjscie = " lutego ";
        break;
    case 3:
        wyjscie = " marca ";
        break;
    case 4:
        wyjscie = " kwietnia ";
        break;
    case 5:
        wyjscie = " maja ";
        break;
    case 6:
        wyjscie = " czerwca ";
        break;
    case 7:
        wyjscie = " lipca ";
        break;
    case 8:
        wyjscie = " sierpnia ";
        break;
    case 9:
        wyjscie = " września ";
        break;
    case 10:
        wyjscie = " października ";
        break;
    case 11:
        wyjscie = " listopada ";
        break;
    case 12:
        wyjscie = " grudnia ";
        break;
    default:
        wyjscie = std::to_string(miesiac_);
        break;
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

auto Data::Poprawna() -> bool const
{
    return poprawna_;
}

auto Data::Wypisz() -> std::string const
{
    return(std::to_string(dzien_) + nazywajMiesiac() + std::to_string(rok_) + "r.");
}

auto Data::operator<(Data D) -> bool const
{
    if (rok_ != D.Rok())
        return rok_ < D.Rok();
    else if (miesiac_ != D.Miesiac())
        return miesiac_ < D.Miesiac();
    else
        return dzien_ < D.Dzien();
}
