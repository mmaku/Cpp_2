#ifndef POZAR_HPP_INCLUDED
#define POZAR_HPP_INCLUDED

#include "podryzyko.hpp"

class Pozar
    : public Podryzyko
{
    public:
        Pozar(void)
            : Podryzyko(0.01)
        {
        }
};

#endif // POZAR_HPP_INCLUDED
