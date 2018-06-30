#include "notowania.hpp"

#include <cmath>

para::para(std::string napis, double wartosc)
    : napis_(napis), wartosc_(wartosc)
{}


void notowania::pop_back(para p)
{
    if(notowania_.empty()){notowania_.push_back(p);}
    else
    {
        int d=notowania_.size()-1;
        int i=0;
        int l=0;
        while (i<=d && l==0)
        {
            if(notowania_[i].napis_==p.napis_)
            {
                notowania_[i].wartosc_=p.wartosc_;
                l=1;
            }

            else
                i=i+1;
        }
        if(i==d+1 && l==0)
        {notowania_.push_back(p);}
    }
}

double notowania::wartosc(std::string napis) const
{
    double wyjscie=NAN;
    if(!notowania_.empty())
    {
        int d=notowania_.size()-1;
        int i=0;
        while (std::isnan(wyjscie) && i<=d)
        {
            if(notowania_[i].napis_==napis)
                wyjscie=notowania_[i].wartosc_;

            else
                i=i+1;
        }
    }
return wyjscie;
}

int notowania::size() const
{
    return notowania_.size();
}

para notowania::operator[](int indeks) const
{
    return notowania_[indeks];
}

para notowania::operator[](int& indeks)
{
    return notowania_[indeks];
}

bool notowania::empty() const
{
    return notowania_.empty();
}
