#ifndef BIO_HPP_INCLUDED
#define BIO_HPP_INCLUDED

#include "identyfikator.hpp"

bool sensownyBIO(std::string B);

class BIO
    : public Identyfikator
{
    private:
        char a_, b_, c_, d_, e_ ,f_ , g_, h_, i_, j_;
        bool sensowny_ = true;

    public:
        BIO(std::string wejscie);
        auto Napis() -> std::string const override final;
        auto CzySensowny() -> bool const override final;
};

#endif // BIO_HPP_INCLUDED
