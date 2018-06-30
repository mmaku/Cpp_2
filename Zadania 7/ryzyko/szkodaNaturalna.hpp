#ifndef SZKODANATURALNA_HPP_INCLUDED
#define SZKODANATURALNA_HPP_INCLUDED

#include "podryzyko.hpp"

class SzkodaNaturalna
    : public Podryzyko
{
    public:
        SzkodaNaturalna(void)
            : Podryzyko(0.02)
        {
        }
};

#endif // SZKODANATURALNA_HPP_INCLUDED
