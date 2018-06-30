#include "gielda.hpp"

gielda::gielda(std::string nazwaGieldy, notowania spolki)
    : nazwaGieldy_(nazwaGieldy), spolki_(spolki)
{}

std::string gielda::nazwa() const
{
    return nazwaGieldy_;
}

std::string gielda::nazwaSpolki(unsigned int indeks) const
{
    return spolki_[indeks].napis_;
}

unsigned int gielda::iloscSpolek() const
{
    return spolki_.size();
}

para gielda::operator[](int indeks) const
{
    return spolki_[indeks];
}

para gielda::operator[](int& indeks)
{
    return spolki_[indeks];
}

void gielda::dodajSpolke(para spolka)
{
    spolki_.pop_back(spolka);
}
