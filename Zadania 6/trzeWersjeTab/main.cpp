#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>

#include "wersja_i.hpp"
#include "wersja_ii.hpp"
#include "wersja_iii.hpp"

const int iloscIter = 10000;

template<typename T>
void test_IntTab()
{
    std::vector<T> a;
    for (int i = 1; i <= iloscIter; ++i)
    {
        a.push_back(T(i));
    }

    std::vector<T> b;
    b = std::move(a);

//        std::move
//        Returns an rvalue reference to arg.
}

template<typename T>
double IntTab_time(void)
{
    std::chrono::time_point<std::chrono::system_clock> poczatek, koniec;
    poczatek = std::chrono::system_clock::now();
    test_IntTab<T>();
    koniec = std::chrono::system_clock::now();
    std::chrono::duration<double> czas = koniec - poczatek;
    return czas.count();
}

int main(void)
{
    std::cout << "IntTab_III (bez &&): " << IntTab_time<IntTab_III>() << "s\n";
    std::cout << "IntTab_I (&& i except): " << IntTab_time<IntTab_I>() << "s\n";
    std::cout << "IntTab_II (&& i noexcept): " << IntTab_time<IntTab_II>() << "s\n";
    return 0;
}
