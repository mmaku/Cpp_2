#include "foo.hpp"

para::para(std::string napis, double liczba)
    : napis_(napis), liczba_(liczba)
{}

void foo::dodajPare(para p)
{
    if(foo_.empty()){foo_.push_back(p);}
    else
    {
        int d=foo_.size()-1;
        int i=0;
        int kontrola=false;

        while (i<=d && kontrola==false)
        {
            if(foo_[i].napis_==p.napis_)
            {
                foo_[i].liczba_=p.liczba_;
                kontrola=true;
            }

            else
                i=i+1;
        }
        if(i==d+1 && kontrola==false)
        {
            foo_.push_back(p);
        }
    }
}

double foo::operator()(std::string napis) const
{
    double wyjscie=NAN;
    bool kontrola = false;

    if(!foo_.empty())
    {
        int d=foo_.size()-1;
        int i=0;
        while (std::isnan(wyjscie) && i<=d)
        {
            if(foo_[i].napis_==napis)
            {
                wyjscie=foo_[i].liczba_;
                kontrola = true;
            }
            else
                i=i+1;
        }
    }

    if(kontrola == true)
        return wyjscie;
    else
        throw brakKlucza{};
}
