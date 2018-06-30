#include "pesel.hpp"
#include "konwersja.hpp"
#include "data.hpp"

bool sensownyPESEL(std::string P)
{
    bool kontrola = true;
    int dzien = 0, miesiac = 0, rok = 0;

    kontrola &= (P.size() == 11);


    if(kontrola)
    {
        for(int i=0; i < 11; i++)
            {
                if(0 <= char2int(P[i]) && char2int(P[i]) <= 9);
                else kontrola = false;
            }
    }

    if(kontrola)
    {
        switch(char2int(P[2]))
        {
            case 0:;
            case 1: {miesiac = char2int(P[2])*10 + char2int(P[3]); rok = 1900; break;}
            case 2:;
            case 3: {miesiac = char2int(P[2])*10 + char2int(P[3]) - 20; rok = 2000; break;};
            case 4:;
            case 5: {miesiac = char2int(P[2])*10 + char2int(P[3]) - 40; rok = 2100; break;};
            case 6:;
            case 7: {miesiac = char2int(P[2])*10 + char2int(P[3]) - 60; rok = 2200; break;};
            case 8:;
            case 9: {miesiac = char2int(P[2])*10 + char2int(P[3]) - 80; rok = 2300; break;};
        }

        dzien = char2int(P[4])*10 + char2int(P[5]);
        rok += char2int(P[0])*10 + char2int(P[1]);
        kontrola = Sensowna(dzien, miesiac, rok);
    }

    return kontrola;
}



PESEL::PESEL(std::string wejscie = "11111111111")
{
        sensowny_ = sensownyPESEL(wejscie);
        a_ = wejscie[0];
        b_ = wejscie[1];
        c_ = wejscie[2];
        d_ = wejscie[3];
        e_ = wejscie[4];
        f_ = wejscie[5];
        g_ = wejscie[6];
        h_ = wejscie[7];
        i_ = wejscie[8];
        j_ = wejscie[9];
        k_ = wejscie[10];
}

std::string PESEL::napis() const
{
    std::string wyjscie;
    std::ostringstream wy;
    wy << a_ << b_ << c_ << d_ << e_ << f_ << g_ << h_ << i_ << j_ << k_;
    return(wy.str());
}

Data PESEL::DataUrodzenia() const
{
    int dzien = 0, miesiac = 0, rok = 0;
    switch(char2int(c_))
    {
        case 0 :;
        case 1 : {miesiac = char2int(c_)*10 + char2int(d_); rok = 1900; break;}
        case 2 :;
        case 3 : {miesiac = char2int(c_)*10 + char2int(d_) - 20; rok = 2000; break;};
        case 4 :;
        case 5 : {miesiac = char2int(c_)*10 + char2int(d_) - 40; rok = 2100; break;};
        case 6 :;
        case 7 : {miesiac = char2int(c_)*10 + char2int(d_) - 60; rok = 2200; break;};
        case 8 :;
        case 9 : {miesiac = char2int(c_)*10 + char2int(d_) - 80; rok = 2300; break;};
    }

    dzien = char2int(e_)*10 + char2int(f_);
    rok += char2int(a_)*10 + char2int(b_);
    return(Data(dzien, miesiac, rok));
}

bool PESEL::czyKobieta() const
{
    return(char2int(j_)%2 == 0);
}

bool PESEL::czyPoprawnaKontrolna() const
{
    int liczba = char2int(a_)
               + 3*char2int(b_)
               + 7*char2int(c_)
               + 9*char2int(d_)
               + 1*char2int(e_)
               + 3*char2int(f_)
               + 7*char2int(g_)
               + 9*char2int(h_)
               + 1*char2int(i_)
               + 3*char2int(j_);

    liczba %= 10;
    liczba = (10-liczba)%10;
    return(liczba == char2int(k_));
}

bool PESEL::czySensowny() const
{
    return sensowny_;
}

////////////////////////////////////////////////////////////////////TESTY/////////////////////////////////////////////////////////////////////////////

void test_sensownyPESEL()
{
    assert(sensownyPESEL("44051401358"));
    assert(sensownyPESEL("93051008752"));
    assert(sensownyPESEL("95990502585") == false);
    assert(sensownyPESEL("95050502589"));
    assert(sensownyPESEL("65161408936") == false);
    assert(sensownyPESEL("65021408938"));
    assert(sensownyPESEL("65424008936") == false);
    assert(sensownyPESEL("65421408930"));
    assert(sensownyPESEL("168468468468468464") == false);
    assert(sensownyPESEL("asdsadasdasdasdsadas") == false);
}

void test_czyPoprawny()
{
    assert(PESEL("44051401358").czyPoprawnaKontrolna() == false);
    assert(PESEL("93051008752").czyPoprawnaKontrolna());
    assert(PESEL("95050502585").czyPoprawnaKontrolna() == false);
    assert(PESEL("95050502589").czyPoprawnaKontrolna());
    assert(PESEL("65021408936").czyPoprawnaKontrolna() == false);
    assert(PESEL("65021408938").czyPoprawnaKontrolna());
    assert(PESEL("65421408938").czyPoprawnaKontrolna() == false);
    assert(PESEL("65421408930").czyPoprawnaKontrolna());
}

void test_napis()
{
    assert(PESEL("44051401358").napis() == "44051401358");
    assert(PESEL("95050502585").napis() == "95050502585");
    assert(PESEL("65021408936").napis() == "65021408936");
    assert(PESEL("65421408938").napis() == "65421408938");
}

void test_DataUrodzenia()
{
    assert(PESEL("93051008752").DataUrodzenia() == Data(10, 05, 1993));
    assert(PESEL("95050502589").DataUrodzenia() == Data(05, 05, 1995));
    assert(PESEL("65021408938").DataUrodzenia() == Data(14, 02, 1965));
    assert(PESEL("65421408930").DataUrodzenia() == Data(14, 02, 2165));
}

void testPESEL()
{
    test_sensownyPESEL();
    test_czyPoprawny();
    test_napis();
    test_DataUrodzenia();

    std::cerr << "test_PESEL ok!\n";
}
