#ifndef OSOBA_HPP_INCLUDED
#define OSOBA_HPP_INCLUDED

#include <string>

class Osoba
{
    private:
        std::string imie_;
        std::string nazwisko_;

    public:
        Osoba(std::string imie, std::string nazwisko)
            : imie_(imie), nazwisko_(nazwisko)
        {
        }

        auto ImieNazwisko() const -> std::string
        {
            return imie_ + " " + nazwisko_;
        }

        auto Imie() const -> std::string
        {
            return imie_;
        }

         auto Nazwisko() const -> std::string
        {
            return nazwisko_;
        }
};

#endif // OSOBA_HPP_INCLUDED
