#include "foo.hpp"
#include "app.hpp"

#include <cassert>


void test();

int main(void)
{
    test();

    foo M;
    aplikacja(M);

    return 0;
}

void test()
{
    para p1("PLN", 1.4);
    para p2("USD", 2.5);
    para p3("YEN", 3.6);
    para p4("EUR", 4.7);
    para p5("CZE", 5.8);
    para p6("zloto", 6.6);
    para p7("srebro", 7.5);
    para p8("braz", 8.4);
    para p9("diament", 9.7);
    para p10("szmaragd", 10.6);
    para p11("CZE",11.0);

    foo P1;
    P1.dodajPare(p1);
    P1.dodajPare(p2);
    P1.dodajPare(p3);
    P1.dodajPare(p4);
    P1.dodajPare(p5);
    P1.dodajPare(p6);
    P1.dodajPare(p7);
    P1.dodajPare(p8);
    P1.dodajPare(p9);
    P1.dodajPare(p10);
    P1.dodajPare(p11);

    assert(P1("PLN")==1.4);
    assert(P1("CZE")==11.0);

    std::cerr<<"testy ok\n";
}
