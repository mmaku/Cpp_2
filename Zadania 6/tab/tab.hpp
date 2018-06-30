#ifndef TAB_HPP_INCLUDED
#define TAB_HPP_INCLUDED

#include <algorithm> // std::swap, std::copy
#include "grid.hpp"

template<typename T>
class Tab
{

    private:
        int rozmiar_;
        T* wsk_tab_;

    public:
        Tab(int rozmiar = 0)
            : rozmiar_(rozmiar), wsk_tab_(nullptr)
        {
            if (rozmiar > 0)
                wsk_tab_ = new T[rozmiar];
        }

        Tab(const Tab& a)
            : rozmiar_(a.rozmiar_)
        {
            assert(a.size() >= 0);
            if (a.wsk_tab_)
            {
                wsk_tab_ = new T[a.rozmiar_];
                std::copy(a.wsk_tab_, a.wsk_tab_ + a.rozmiar_, wsk_tab_);

                /*
                Sygnatura std::copy
                                        template< class InputIt, class OutputIt >
                                        OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
                */

            }
        }

        ~Tab(void)
        {
            delete[] wsk_tab_;
        }

        void swap(Tab& a)
        {
            std::swap(wsk_tab_, a.wsk_tab_);
            std::swap(rozmiar_, a.rozmiar_);
        }

        Tab& operator=(Tab a)
        {
            swap(a);
            return *this;
        }

        T& operator[](int a) const
        {
            assert(0 <= a && a < rozmiar_);
            return wsk_tab_[a];
        }

        T& operator[](int a)
        {
            assert(0 <= a && a < rozmiar_);
            return wsk_tab_[a];
        }

        int size(void) const
        {
            return rozmiar_;
        }
};

template<typename T>
void swap(Tab<T>& a, Tab<T>& b)
{
    a.swap(b);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void test_Tab()
{
    Tab<int> it(5);
    it[0]=10;
    it[4]=20;
    assert(it.size()==5);
    assert(it[0]==10);
    assert(it[4]==20);

    Tab<int> iu(10);
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

    Tab<Grid> is(4);
    assert(is.size()==4);
    is[0] = Grid(1, 2);
    is[1] = Grid(3, 4);
    is[2] = Grid(5, 6);
    assert(is[0].X() == 1);
    assert(is[2].Y() == 6);
    assert(is[1] == Grid(3, 4));

    Tab<Grid> iz(is);
    Tab<Grid> ic(4);
    assert(iz.size() == 4);
    assert(iz[3] == Grid(0, 0));
    assert(iz[0] == Grid(1, 2));

    ic.swap(is);
    ic = iz;
    assert(ic[2].Y() == 6);
    assert(is[0] == Grid(0, 0));

    std::cerr << "test_Tab ok!\n";
}

#endif // TAB_HPP_INCLUDED
