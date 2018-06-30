#include <iostream>
#include <cassert>
#include <sstream>
#include <vector>
#include <memory>

#include "osobaFizyczna.hpp"
#include "firma.hpp"
#include "fundacja.hpp"

std::unique_ptr<Podatnik> wczytajPodatnika(std::istream& we)
{
    std::string wejscie;
    we >> wejscie;
    if (we)
    {
        if (wejscie ==  "<osoba")
        {
            std::string imie;
            std::string nazwisko;
            std::string pesel;
            int rok;
            int miesiac;
            int dzien;
            we >> imie >> nazwisko >> pesel >> rok >> miesiac >> dzien;
            we.get();
            if (we)
            {
                std::unique_ptr<Podatnik> a(new OsobaFizyczna(imie, nazwisko, pesel,
                                                          rok, miesiac, dzien));
                return a;
            }
        }
        else if (wejscie =="<firma")
        {
            std::string nazwa;
            std::string nip;
            we >> nazwa;
            we >> nip;
            we.get();
            if (we)
            {
                std::unique_ptr<Podatnik> a(new Firma(nazwa, nip));
                return a;
            }
        }
        else if (wejscie == "<fundacja")
        {
            std::string nazwa;
            std::string krs;
            bool pub;
            we >> nazwa >> krs >> pub;
            we.get();
            if (we)
            {
                std::unique_ptr<Podatnik> a(new Fundacja(nazwa, krs, pub));
                return a;
            }
        }
    }
    we.setstate(std::ios::failbit);
    return std::unique_ptr<Podatnik>();
}

std::vector<std::unique_ptr<Podatnik> > wczytajPodatnikow(std::istream& we)
{
    std::vector<std::unique_ptr<Podatnik>> v;
    while (we)
    {
        std::unique_ptr<Podatnik> hp(wczytajPodatnika(we)); // dziala tez operator przypisania
        if (hp)
          v.push_back(std::move(hp));
    }
    return v;
}

void test_Podatnicy();

int main()
{
    test_Podatnicy();
    testPESEL();
    return 0;
}

void test_Podatnicy()
{
    std::istringstream is(
                        "<firma SKLEP 124-40-12-931>\n"
                        "<fundacja POMAGAMY 4010682286 1>\n"
                        "<osoba Jan Kowalski 92051702313 92 05 17>\n"
                        "<firma ROWERY 143-55-34-561>\n"
                        "<fundacja ZWIERZETA 4280144286 0>\n"
                        "<firma DOBRO 941-30-73-153>\n"
                        "<osoba Jan Nowak 99884402313 99 04 04>\n"
                        "<firma TESCO 104-50-03-271>\n"
                        "<fundacja POMOC 4010583286 0>\n"
                        "<osoba Jan Kaczmarek 12567823451 75 08 04>\n"
                        "<firma SPORT 114-50-03-271>\n"
                        );
    std::vector<std::unique_ptr<Podatnik> > v = wczytajPodatnikow(is);
    for (int i = 0; i < int(v.size()); ++i)
    {
        std::cout << v[i]->Dane() << "\n";
    }
}
