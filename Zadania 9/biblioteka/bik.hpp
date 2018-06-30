#ifndef BIK_HPP_INCLUDED
#define BIK_HPP_INCLUDED

#include "identyfikator.hpp"

bool sensownyBIK(std::string B);

class BIK
    : public Identyfikator
{
    private:
        char a_, b_, c_, d_, e_ ,f_ , g_, h_, i_, j_;
        bool sensowny_ = true;

    public:
        BIK(std::string wejscie);
        auto Napis() -> std::string const override final;
        auto CzySensowny() -> bool const override final;
};

#endif // BIK_HPP_INCLUDED
