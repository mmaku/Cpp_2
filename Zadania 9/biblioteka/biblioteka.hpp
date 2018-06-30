#ifndef BIBLIOTEKA_HPP_INCLUDED
#define BIBLIOTEKA_HPP_INCLUDED

#include <memory>
#include <string>
#include "osoba.hpp"
#include "klient.hpp"
#include "obiekt.hpp"
#include "wypozyczenie.hpp"

class Biblioteka
{

    private:
        std::vector<std::unique_ptr<Obiekt> > zasoby_;
        std::vector<std::unique_ptr<Klient> > klienci_;
        std::vector<std::unique_ptr<Wypozyczenie> > wypozyczenia_;

    public:
        auto DodajKlienta(std::string bik, std::string nazwa) -> void;
        auto DodajKlienta(std::string bik, std::string imie, std::string nazwisko) -> void;
        auto DodajKsiazke(std::string bio, std::string tytul, std::vector<Osoba> autorzy) -> void;
        auto DodajDvd(std::string bio, std::string tytul, Osoba rezyser, std::vector<Osoba> obsada) -> void;

        auto WypozyczenieZasobu(Data koniec, std::string bio, std::string bik) -> void;
        auto Zwrot(std::string bio) -> void;
        auto ListaWypozyczen(void) -> void;
        auto ListaWypozyczenKlienta(std::string bik) -> void const;
};

#endif // BIBLIOTEKA_HPP_INCLUDED
