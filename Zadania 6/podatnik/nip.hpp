#ifndef NIP_HPP_INCLUDED
#define NIP_HPP_INCLUDED

#include<string>

bool sensownyNIP(std::string N);

class NIP
{
    private:
        char a_, b_, c_, d_, e_ ,f_ , g_, h_, i_, j_;
        bool sensowny_ = true;

    public:
        NIP(std::string wejscie);
        std::string napis() const;
        bool czyPoprawnaKontrolna() const;
};
#endif // NIP_HPP_INCLUDED
