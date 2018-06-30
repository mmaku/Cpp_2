#ifndef OSOBA_HPP_INCLUDED
#define OSOBA_HPP_INCLUDED

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

        auto ImieNazwisko(void) const -> std::string
        {
            return imie_ + " " + nazwisko_;
        }
};

#endif // OSOBA_HPP_INCLUDED
