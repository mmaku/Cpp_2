#ifndef INTTAB_HPP_INCLUDED
#define INTTAB_HPP_INCLUDED

#include <algorithm>

class IntTab
{
    private:
        int rozmiar_;
        int* wsk_tab_;

    public:
        explicit IntTab(int rozmiar=0);
        IntTab(const IntTab& a);
        ~IntTab();
        int size() const;
        void swap(IntTab& a) noexcept;
        IntTab operator=(IntTab a);
        int operator[](int a) const;
//        a może:
//        int& operator[](int a) const;
        int& operator[](int a);
};

void swap(IntTab& a, IntTab& b);
void test_IntTab();


#endif // INTTAB_HPP_INCLUDED
