#include "firma.hpp"

Firma::Firma(std::string nazwa, std::string nip)
  : nazwa_(nazwa), nip_(nip)
{}

std::string Firma::Dane(void)
{
    return "<firma " + nazwa_ + " " + nip_.napis() + ">";
}
