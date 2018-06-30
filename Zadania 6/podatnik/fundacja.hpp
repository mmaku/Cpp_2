#ifndef FUNDACJA_H_
#define FUNDACJA_H_

#include <string>
#include "podatnik.hpp"

class Fundacja
    : public Podatnik
{
    private:
        std::string nazwa_;
        std::string krs_;

    public:
        Fundacja(std::string nazwa, std::string krs, bool oup);
        std::string Dane() override final;
        bool oup_;
};

#endif /* FUNDACJA_H_ */
