#include <algorithm> // std::swap & std::copy
#include <cassert>

#include "wersja_iii.hpp"

//        Wiele pomyslow pochodzi z:
//        http://msdn.microsoft.com/pl-pl/library/dd293665.aspx

IntTab_III::IntTab_III(int rozmiar)
    : rozmiar_(rozmiar), wsk_tab_(nullptr)
{
    if (rozmiar > 0)
        wsk_tab_ = new int[rozmiar];
}

IntTab_III::IntTab_III(const IntTab_III& a)
  : rozmiar_(a.rozmiar_), wsk_tab_(nullptr)
{
    if (a.wsk_tab_)
    {
        wsk_tab_ = new int[a.rozmiar_];
        std::copy(a.wsk_tab_, a.wsk_tab_ + a.rozmiar_, wsk_tab_);
    }
}

void IntTab_III::swap(IntTab_III& a) noexcept
{
    std::swap(wsk_tab_, a.wsk_tab_);
    std::swap(rozmiar_, a.rozmiar_);
}

void swap(IntTab_III& a, IntTab_III& b)
{
    a.swap(b);
}

IntTab_III IntTab_III::operator=(const IntTab_III& a)
{
    if (this != &a)
    {
        delete[] wsk_tab_; // uwalnianie pamieci

        rozmiar_ = a.size();
        wsk_tab_ = new int[rozmiar_];
        std::copy(a.wsk_tab_, a.wsk_tab_ + rozmiar_, wsk_tab_);
    }
    return *this;
}

IntTab_III::~IntTab_III()
{
    if (wsk_tab_ != NULL) // potrzebne?
        delete[] wsk_tab_;
}

int IntTab_III::size() const
{
    return rozmiar_;
}

int IntTab_III::operator[](int a) const
{
    assert(0 <= a && a < rozmiar_);
    return wsk_tab_[a];
}

int& IntTab_III::operator[](int a)
{
    assert(0 <= a && a < rozmiar_);
    return wsk_tab_[a];
}
