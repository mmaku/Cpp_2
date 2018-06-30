#include "wersja_ii.hpp"

IntTab_II::IntTab_II(int rozmiar)
    : IntTab_III(rozmiar)
{}

IntTab_II::IntTab_II(const IntTab_II& a)
    : IntTab_III(a)
{}

IntTab_II::IntTab_II(IntTab_II&& a)
    : size_(0), tab_ptr_(nullptr)
{
    swap(a);
}

IntTab_II IntTab_II::operator=(IntTab_II&& a)
{
    swap(a);
    return *this;
}
