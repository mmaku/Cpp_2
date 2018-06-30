#include "foo.hpp"
#include "app.hpp"

 double pobieranieZmiennych (std::string polecenie)
 {
    std::string wejscie;
    double liczba = 0.0;

    std::cout << polecenie;
    std::cin >> wejscie;
    std::istringstream strumien(wejscie);
    strumien >> liczba;

    while (strumien.fail())
    {
        strumien.clear();
        std::cout << "Podana wartość nie jest liczbą."
                  << "\nPodaj liczbę jeszcze raz: ";
        std::cin >> wejscie;
        strumien.str (wejscie);
        strumien >> liczba;
    }

    std::cout << '\n';
    return(liczba);
 }

void aplikacja(foo& m)
{
    int odpowiedz;
    while(odpowiedz != 3)
    {
        std::cout << "Aby wyświetlić dane podaj \"1\" i wciśnij \"Enter\",\n"
                  << "aby edytować podaj \"2\" i wciśnij \"Enter\".\n"
                  << "Podaj \"3\" aby wyjść.\n";
        std::cin >> odpowiedz;

        if (odpowiedz==1)
            wyswietlanie(m);
        else if (odpowiedz==2)
            wpisywanie(m);
        else if (odpowiedz != 3)
            std::cout << "Podany znak jest błędny";
    }
    std::cout << "Żegnam\n";
}


void wyswietlanie(foo& m)
{
    std::string wejscie;
    std::cout << "Podaj klucz: ";
    std::cin >> wejscie;

    try
    {
        std::cout << "\nWartość klucza " << wejscie << " to " << m(wejscie) << '\n';
    }
    catch(brakKlucza& bk)
    {
        std::cout << "\nNie ma takiego klucza, przykro mi...\n";
    }
}
void wpisywanie(foo& m)
{
    std::cout << "Zostaniesz teraz poproszony o padanie parametrów pary...\n";
    std::string wejscie1;
    std::cout << "Podaj klucz: ";
    std::cin >> wejscie1;

    double wejscie2 = pobieranieZmiennych("Podaj warość liczbową: ");


    m.dodajPare(para(wejscie1, wejscie2));
}
