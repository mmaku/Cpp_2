#include "bio.hpp"

bool sensownyBIK(std::string B)
{
    bool kontrola = true;

    kontrola &= (B.size() == 10);


    if(kontrola)
    {
        for(int i=0; i < 11; i++)
            {
                if(0 <= char2int(B[i]) && char2int(B[i]) <= 9);
                else kontrola = false;
            }
    }

    return kontrola;
}



BIO::BIO (std::string wejscie)
{
        sensowny_ = sensownyBIK(wejscie);
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

auto BIO::Napis() -> std::string const
{
    char pauza = '-';
    std::string wyjscie;
    std::ostringstream wy;
    wy << a_ << b_ << c_ << pauza << d_ << e_ << pauza << f_ << g_ << pauza << h_ << i_ << j_ ;
    return(wy.str());
}

auto BIO::CzySensowny() -> bool const
{
    return sensowny_;
}
