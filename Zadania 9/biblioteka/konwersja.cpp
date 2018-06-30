#include "konwersja.hpp"

int char2int (char a)
{
    int wyjscie = -1;
    switch(a)
    {
        case '0' : wyjscie = 0; break;
        case '1' : wyjscie = 1; break;
        case '2' : wyjscie = 2; break;
        case '3' : wyjscie = 3; break;
        case '4' : wyjscie = 4; break;
        case '5' : wyjscie = 5; break;
        case '6' : wyjscie = 6; break;
        case '7' : wyjscie = 7; break;
        case '8' : wyjscie = 8; break;
        case '9' : wyjscie = 9; break;
    }
    return(wyjscie);
}

