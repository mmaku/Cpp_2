#ifndef WERSJA_II_INCLUDED
#define WERSJA_II_INCLUDED

#include "wersja_iii.hpp"

class IntTab_II
    : public IntTab_III
{
    private:
        int size_;
        int* tab_ptr_;

    public:
        explicit IntTab_II(int rozmiar = 0);
        IntTab_II(const IntTab_II& a);
        IntTab_II(IntTab_II&& a);
        IntTab_II operator=(IntTab_II&& a);

};

#endif // WERSJA_III_INCLUDED
