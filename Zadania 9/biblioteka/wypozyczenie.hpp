#ifndef WYPOZYCZENIE_HPP_INCLUDED
#define WYPOZYCZENIE_HPP_INCLUDED

#include "data.hpp"
#include "bio.hpp"
#include "bik.hpp"

class Wypozyczenie
{
    private:
//        Data poczatek_
        Data koniec_;
        BIO bio_;
        BIK bik_;

    public:
        Wypozyczenie(Data koniec, std::string bio, std::string bik)
            : koniec_(koniec), bio_(bio), bik_(bik)
        {
        }

        auto TerminZwrotu() -> Data
        {
            return koniec_;
        }

        auto napisBIO() -> std::string const
        {
            return bio_.Napis();
        }
        auto napisBIK() -> std::string const
        {
            return bik_.Napis();
        }
};

#endif // WYPOZYCZENIE_HPP_INCLUDED
