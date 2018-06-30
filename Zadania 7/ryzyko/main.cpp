#include <iostream>
#include "ryzyko.cpp"
#include <string>

void test_Ryzyko();

int main()
{
    test_Ryzyko();
    return 0;
}

void test_Ryzyko()
{
    Ryzyko polisa(30000.0, 28, "Opel", "Corsa", 1.6, 2010);
    polisa.DodajPodryzyko("szkoda naturalna");
    polisa.DodajPodryzyko("wypadek");
    polisa.DodajPodryzyko("pozar");
    std::cout << "Ogolna stawka (bez OC): " << polisa.Stawka() << " od wartosci pojazdu\n";
    std::cout << "Kwota do zaplaty: " << polisa.Kwota() << " zl\n";
}
