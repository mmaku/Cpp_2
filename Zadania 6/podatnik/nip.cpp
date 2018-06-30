#include "nip.hpp"
#include "konwersja.hpp"

bool sensownyNIP(std::string N)
{
    bool kontrola = true;

    kontrola &= (N.size() == 10);


    if(kontrola)
    {
        for(int i=0; i < 11; i++)
            {
                if(0 <= char2int(N[i]) && char2int(N[i]) <= 9);
                else kontrola = false;
            }
    }

    return kontrola;
}



NIP::NIP (std::string wejscie)
{
        sensowny_ = sensownyNIP(wejscie);
        a_ = wejscie[0];
        b_ = wejscie[1];
        c_ = wejscie[2];
        d_ = wejscie[4];
        e_ = wejscie[5];
        f_ = wejscie[7];
        g_ = wejscie[8];
        h_ = wejscie[10];
        i_ = wejscie[11];
        j_ = wejscie[12];
}

std::string NIP::napis() const
{
    char pauza = '-';
    std::string wyjscie;
    std::ostringstream wy;
    wy << a_ << b_ << c_ << pauza << d_ << e_ << pauza << f_ << g_ << pauza << h_ << i_ << j_ ;
    return(wy.str());
}

bool NIP::czyPoprawnaKontrolna() const
{
    int liczba = 6*char2int(a_)
               + 5*char2int(b_)
               + 7*char2int(c_)
               + 2*char2int(d_)
               + 3*char2int(e_)
               + 4*char2int(f_)
               + 5*char2int(g_)
               + 6*char2int(h_)
               + 7*char2int(i_);

    liczba %= 11;
    return(liczba == char2int(j_));
}
