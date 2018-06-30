#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <cassert>

struct para
{
        std::string napis_;
        double liczba_;

        para(std::string napis, double liczba=0.0);
};

para::para(std::string napis, double liczba)
    : napis_(napis), liczba_(liczba)
{}

class foo
{
    private:
        std::vector<para> foo_;

    public:
        void dodajPare(para p);
        double Liczba(std::string napis) const;
        int Dlugosc() const;
        bool Pusty() const;
        para operator[](int indeks) const;
};

void foo::dodajPare(para p)
{
    if(foo_.empty()){foo_.push_back(p);}
    else
    {
        int d=foo_.size()-1;
        int i=0;
        int l=0;
        while (i<=d && l==0)
        {
            if(foo_[i].napis_==p.napis_)
            {
                foo_[i].liczba_=p.liczba_;
                l=1;
            }

            else
                i=i+1;
        }
        if(i==d+1 && l==0)
        {foo_.push_back(p);}
    }
}

double foo::Liczba(std::string napis) const
{
    double wyjscie=NAN;
    if(!foo_.empty())
    {
        int d=foo_.size()-1;
        int i=0;
        while (std::isnan(wyjscie) && i<=d)
        {
            if(foo_[i].napis_==napis)
                wyjscie=foo_[i].liczba_;

            else
                i=i+1;
        }
    }
return wyjscie;
}

int foo::Dlugosc() const
{
    return foo_.size();
}

para foo::operator[](int indeks) const
{
    return foo_[indeks];
}

bool foo::Pusty() const
{
    return foo_.empty();
}

void test();

int main(void)
{
    test();
    return 0;
}

void test()
{
    para p1("PLN", 1.4);
    para p2("USD", 2.5);
    para p3("YEN", 3.6);
    para p4("EUR", 4.7);
    para p5("CZE", 5.8);
    para p6("zloto", 6.6);
    para p7("srebro", 7.5);
    para p8("braz", 8.4);
    para p9("diament", 9.7);
    para p10("szmaragd", 10.6);
    para p11("CZE",11.0);

    foo P1;
    assert(P1.Pusty());
    P1.dodajPare(p1);
    P1.dodajPare(p2);
    P1.dodajPare(p3);
    P1.dodajPare(p4);
    P1.dodajPare(p5);
    P1.dodajPare(p6);
    P1.dodajPare(p7);
    P1.dodajPare(p8);
    P1.dodajPare(p9);
    P1.dodajPare(p10);
    P1.dodajPare(p11);

    assert(P1.Dlugosc()==10);
    assert(P1[4].liczba_==11.0);
    assert(P1[9].napis_=="szmaragd");
    assert(P1.Liczba("PLN")==1.4);
    assert(P1.Liczba("CZE")==11.0);
    assert(std::isnan(P1.Liczba("napis")));

    std::cerr<<"testy ok\n";
}
