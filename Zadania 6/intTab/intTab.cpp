#include <algorithm>
#include <iostream>
#include <cassert>
#include "intTab.hpp"

IntTab::IntTab(int rozmiar)
  : rozmiar_(rozmiar), wsk_tab_(nullptr)
{
    if (rozmiar > 0)
        wsk_tab_ = new int[rozmiar];
}

IntTab::IntTab(const IntTab& a)
  : rozmiar_(a.rozmiar_), wsk_tab_(nullptr)
{
    if (a.wsk_tab_)
    {
        wsk_tab_ = new int[a.rozmiar_];
        std::copy(a.wsk_tab_, a.wsk_tab_ + a.rozmiar_, wsk_tab_);
    }
}

void IntTab::swap(IntTab& a) noexcept
{
    std::swap(wsk_tab_, a.wsk_tab_);
    std::swap(rozmiar_, a.rozmiar_);
}

void swap(IntTab& a, IntTab& b)
{
    a.swap(b);
}

IntTab IntTab::operator=(IntTab a)
{
    swap(a);
    return *this;
}

IntTab::~IntTab()
{
    delete[] wsk_tab_;
}

int IntTab::size() const
{
    return rozmiar_;
}

int IntTab::operator[](int a) const
{
    assert(0 <= a && a < rozmiar_);
    return wsk_tab_[a];
}

int& IntTab::operator[](int a)
{
    assert(0 <= a && a < rozmiar_);
    return wsk_tab_[a];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void test_IntTab()
{
    IntTab it(5);
    it[0]=10;
    it[4]=20;
    assert(it.size()==5);
    assert(it[0]==10);
    assert(it[4]==20);

    IntTab iu(10);
    iu[0]=17;
    iu[4]=34;
    assert(iu.size()==10);
    assert(iu[0]==17);
    assert(iu[4]==34);

    iu.swap(it);
    assert(iu.size()==5);
    assert(iu[0]==10);
    assert(it.size()==10);
    assert(it[0]==17);

    IntTab is(iu);
    assert(is.size()==5);
    assert(is[0]==10);

    IntTab iw;
    iw = it;
    assert(iw.size()==10);
    assert(iw[0]==17);

    it[0]=1;
    iu[0]=2;
    is[0]=3;
    iw[0]=4;

    assert(it[0]==1);
    assert(iu[0]==2);
    assert(is[0]==3);
    assert(iw[0]==4);

    std::cerr << "test_IntTab ok!\n";
}
