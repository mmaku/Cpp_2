#include "notowania.hpp"
#include "gielda.cpp"

#include <iostream>
#include <cassert>
#include <cmath>

void test()
{
    para pp1("AMICA", 105.75);
    para pp2("BAKALLAND", 2.78);
    para pp3("ELEKTROBUDOWA", 80.95);
    para pp4("HANDLOWY", 114.05);
    para pp5("KGHM POLSKA MIEDZ SA", 127.30);

    para ap1("UNILEVER", 25.16);
    para ap2("LLOYDS", 0.76);
    para ap3("NESTLE", 67.50);
    para ap4("SHELL", 21.73);
    para ap5("ROLLS-ROYCE", 7.96);

    para sp1("SWATCH", 451.90);
    para sp2("CREDIT SUISSE", 25.04);
    para sp3("ADECCO", 62.40);
    para sp4("ZURICH FINANCIAL", 277.80);
    para sp5("NOVARTIS", 84.20);


    assert(pp1.napis_ == "AMICA");
    assert(pp2.napis_ == "BAKALLAND");
    assert(pp3.napis_ == "ELEKTROBUDOWA");
    assert(pp4.napis_ == "HANDLOWY");
    assert(pp5.napis_ == "KGHM POLSKA MIEDZ SA");

    assert(pp1.wartosc_ == 105.75);
    assert(pp2.wartosc_ == 2.78);
    assert(pp3.wartosc_ == 80.95);
    assert(pp4.wartosc_ == 114.05);
    assert(pp5.wartosc_ == 127.30);


    std::cerr<<"testPara ok\n";


    notowania p, a, s;
    assert(p.empty());
    assert(a.empty());
    assert(s.empty());

    p.pop_back(pp1);
    p.pop_back(pp2);
    p.pop_back(pp3);
    p.pop_back(pp4);

    assert(p[0].napis_ == "AMICA");
    assert(p[3].napis_ == "HANDLOWY");

    a.pop_back(ap1);
    a.pop_back(ap2);
    a.pop_back(ap3);
    a.pop_back(ap4);

    assert(a[1].napis_ == "LLOYDS");
    assert(a[2].napis_ == "NESTLE");

    s.pop_back(sp1);
    s.pop_back(sp2);
    s.pop_back(sp3);
    s.pop_back(sp4);

    assert(s[0].napis_ == "SWATCH");
    assert(s[1].napis_ == "CREDIT SUISSE");


    std::cerr<<"testNotowania ok\n";

    notowania z;

    gielda GPW("Gielda Papierow Wartosciowych",  p);
    gielda LSE("London Stock Exchange",  a);
    gielda SSE("SIX Swiss Exchange",  s);
    gielda PUS("PUSTA", z);


    assert(GPW.nazwa()=="Gielda Papierow Wartosciowych");
    assert(LSE.nazwa()=="London Stock Exchange");
    assert(SSE.nazwa()=="SIX Swiss Exchange");

    assert(GPW.iloscSpolek()==4);
    assert(LSE.iloscSpolek()==4);
    assert(SSE.iloscSpolek()==4);
    assert(PUS.iloscSpolek()==0);

    assert(GPW.nazwaSpolki(3) == "HANDLOWY");


    std::cerr<<"testGielda ok\n";
}

   // s[0].napis_ = sp5.napis_;

  //  assert(s[0].napis_ == "NOVARTIS");
  //  assert(s[0].wartosc_ == 84.20);

