#ifndef IDENTYFIKATOR_HPP_INCLUDED
#define IDENTYFIKATOR_HPP_INCLUDED

#include <string>
#include <iostream>
#include <ostream>
#include <sstream>
#include "konwersja.hpp"

class Identyfikator
{
    private:
        bool sensowny_;

    public:
        virtual auto Napis() -> std::string const;
//        virtual ~Identyfikator(void) = 0;
        virtual auto CzySensowny() -> bool const;
};

//Identyfikator::~Identyfikator() = default;

#endif // IDENTYFIKATOR_HPP_INCLUDED
