#include <iostream>
#include <assert.h>

#include "GCD.hpp"

auto test_GCD() -> void
{
    assert(GCD(2,0) == 2);
    assert(GCD(10,5) == 5);
    assert(GCD(7,3) == 1);
    assert(GCD(1000,10) == 10);
    assert(GCD(36,20) == 4);
    std::cerr<<"Testy_GCD ok\n";


    long a = 10;
    long b = 2;
    assert(GCD(a, b) == 2);

    std::cerr<<"Testy_GCD long ok\n";


}
