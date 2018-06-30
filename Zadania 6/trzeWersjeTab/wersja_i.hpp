#ifndef WERSJA_I_HPP_INCLUDED
#define WERSJA_I_HPP_INCLUDED

#include "wersja_iii.hpp"

class IntTab_I
    : public IntTab_III
{
    private:
        int size_;
        int* tab_ptr_;

    public:
        explicit IntTab_I(int rozmiar = 0);
        IntTab_I(const IntTab_I& a);
        IntTab_I(IntTab_I&& a) noexcept;
        IntTab_I operator=(IntTab_I&& a) noexcept;

};

#endif // WERSJA_I_HPP_INCLUDED
