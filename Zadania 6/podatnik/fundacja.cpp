#include "fundacja.hpp"
#include "data.hpp"

Fundacja::Fundacja(std::string nazwa, std::string krs, bool oup)
    : nazwa_(nazwa), krs_(krs), oup_(oup)
{}

std::string Fundacja::Dane(void)
{
    return "<fundacja " + nazwa_ + " " + krs_ + " " + std::to_string(oup_) + ">";
}
