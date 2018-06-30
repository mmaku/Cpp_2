#include <algorithm>
#include <sstream>
#include "biblioteka.hpp"
#include "firma.hpp"
#include "osobaFizyczna.hpp"
#include "ksiazka.hpp"
#include "dvd.hpp"

auto Biblioteka::DodajKlienta(std::string bik,
                              std::string nazwa) -> void
{
    klienci_.push_back(std::unique_ptr<Klient>(new Firma(bik, nazwa)));
}

auto Biblioteka::DodajKlienta(std::string bik,
                              std::string imie,
                              std::string nazwisko) -> void
{
    klienci_.push_back(std::unique_ptr<Klient>(new OsobaFizyczna(bik, imie, nazwisko)));
}

auto Biblioteka::DodajKsiazke(std::string bio,
                              std::string tytul,
                              std::vector<Osoba> autorzy) -> void
{
    zasoby_.push_back(std::unique_ptr<Zasob>(new Ksiazka(bio, tytul, autorzy)));
}

auto Biblioteka::DodajDvd(std::string bio,
                          std::string tytul,
                          Osoba rezyser,
                          std::vector<Osoba> obsada) -> void
{
    zasoby_.push_back(std::unique_ptr<Zasob>(new Dvd(bio, tytul, rezyser, obsada)));
}

auto Biblioteka::WypozyczenieZasobu(Data koniec, std::string bio, std::string bik) -> void
{
    wypozyczenia_.push_back(std::unique_ptr<Wypozyczenie>(new Wypozyczenie(koniec, bio, bik)));
}

auto Biblioteka::Zwrot(std::string bio) -> void
{
    for (int i = 0; i < int(wypozyczenia_.size()); ++i)
    {
        if (wypozyczenia_[i] && wypozyczenia_[i]->BIO() == bio)
        {
            wypozyczenia_[i].reset();
            break;
        }
    }
}

auto Biblioteka::ListaWypozyczen() -> void
{
    std::string lista;

    auto zapisz = [&](const std::unique_ptr<Wypozyczenie>& w)
    {
        if (w)
        {
            lista += w->TerminZwrotu().Wypisz()
            lista += " BIO: " + w->BIO() + ' ';
            lista += " BIK: " + w->BIK() + '\n';
        }
    };

    for_each(std::begin(wypozyczenia_), std::end(wypozyczenia_), zapisz);
    std::cout << lista;
}

auto Biblioteka::ListaWypozyczenKlienta(std::string bik) -> void const
{
    std::string lista;
    auto zapisz = [&](const std::unique_ptr<Wypozyczenie>& w)
    {
        if (w && w->BIK() == bik)
        {
            lista += w->TerminZwrotu().Wypisz()
            lista += " BIO: " + w->BIO() + '\n';
        }
    };
    for_each(std::begin(wypozyczenia_), std::end(wypozyczenia_), zapisz);
    std::cout << lista;
}
