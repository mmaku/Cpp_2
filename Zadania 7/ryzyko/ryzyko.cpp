#include "ryzyko.hpp"
#include "wypadek.hpp"
#include "pozar.hpp"
#include "szkodaNaturalna.hpp"

Ryzyko::Ryzyko(double wartosc_pojazdu, int wiek_wlasciciela, std::string marka,
               std::string model, double pojemnosc = 0.0, int rok_produkcji = 0)
    : wartosc_pojazdu_(wartosc_pojazdu),
      wiek_wlasciciela_(wiek_wlasciciela),
      marka_(marka),
      model_(model),
      pojemnosc_(pojemnosc),
      rok_produkcji_(rok_produkcji)

{
}

void Ryzyko::DodajPodryzyko(const std::string& nazwa)
{
    bool kontrola = false;
    if (nazwa == "wypadek")
    {
        podryzyka_.push_back(std::unique_ptr<Podryzyko>(new Wypadek(wiek_wlasciciela_)));
        kontrola = true;
    }
    else if (nazwa == "pozar")
    {
        podryzyka_.push_back(std::unique_ptr<Podryzyko>(new Pozar()));
        kontrola = true;
    }
    else if (nazwa == "szkoda naturalna")
    {
        podryzyka_.push_back(std::unique_ptr<Podryzyko>(new SzkodaNaturalna()));
        kontrola = true;
    }

    if(kontrola)
        ogolna_stawka_ += podryzyka_.back() -> Stawka();
}

double Ryzyko::WartoscPojazdu() const
{
    return wartosc_pojazdu_;
}

double Ryzyko::WiekWlasciciela() const
{
    return wiek_wlasciciela_;
}

const std::string& Ryzyko::Marka() const
{
    return marka_;
}

const std::string& Ryzyko::Model() const
{
    return model_;
}

double Ryzyko::Pojemnosc() const
{
    return pojemnosc_;
}

int Ryzyko::RokProdukcji() const
{
    return rok_produkcji_;
}

double Ryzyko::Stawka() const
{
    return ogolna_stawka_;
}

double Ryzyko::Kwota(void) const
{
    return (ogolna_stawka_ * wartosc_pojazdu_) + (0.0003 * kurs * UKG);
}
