#include "data.hpp"
#include "test.hpp"

#include <iostream>
#include <cassert>
#include <sstream>


auto test_Data() -> void
{
    Data d1(1,2,3);
    assert(d1.Dzien()==1);
    assert(d1.Miesiac()==2);
    assert(d1.Rok()==3);
    assert(d1.zlyD()== false);
    assert(d1.zlyM()==false);
    assert(d1.zlyR()==false);

    Data d2;
    assert(d2.Dzien()==1);
    assert(d2.Miesiac()==1);
    assert(d2.Rok()==1);
    assert(d2.zlyD()== false);
    assert(d2.zlyM()==false);
    assert(d2.zlyR()==false);

    Data d3(400,25,-1);
    assert(d3.Dzien()==400);
    assert(d3.Miesiac()==25);
    assert(d3.Rok()==-1);

    std::cerr << d3.zlyD() << '\n'
              << d3.zlyM() << '\n'
              << d3.zlyR() << '\n';
    assert(d3.zlyD()==true);
    assert(d3.zlyM()==false);
    assert(d3.zlyR()==false);

    std::istringstream we("4 4 6");
    we >> d1;
    assert(we);
    assert(d1.Dzien()==4);
    assert(d1.Miesiac()==4);
    assert(d1.Rok()==6);

    std::cerr << "test_Trojmian ok\n";
}
