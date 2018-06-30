#include "wersja_i.hpp"

IntTab_I::IntTab_I(int rozmiar)
    : IntTab_III(rozmiar)
{}

IntTab_I::IntTab_I(const IntTab_I& a)
    : IntTab_III(a)
{}

IntTab_I::IntTab_I(IntTab_I&& a) noexcept
    : size_(0), tab_ptr_(nullptr)
{
    swap(a);
}

IntTab_I IntTab_I::operator=(IntTab_I&& a) noexcept
{
    swap(a);
    return *this;
}
