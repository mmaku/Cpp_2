#ifndef RYZYKO_HPP_INCLUDED
#define RYZYKO_HPP_INCLUDED

#include <vector>
#include <memory>
#include "podryzyko.hpp"

  const double UKG = 1000000;
  const double kurs = 4.2;

class Ryzyko
{
    private:
        double wartosc_pojazdu_;
        int wiek_wlasciciela_;
        std::string marka_;
        std::string model_;
        double pojemnosc_;
        int rok_produkcji_;

        double ogolna_stawka_ = 0.0;
        double ogolna_kwota_ = 0.0;

        std::vector<std::unique_ptr<Podryzyko>> podryzyka_;

    public:
        Ryzyko(double wartosc_pojazdu, int wiek_wlasciciela, std::string marka,
               std::string model, double pojemnosc, int rok_produkcji);

        void DodajPodryzyko(const std::string& nazwa);
        double WartoscPojazdu() const;
        double WiekWlasciciela() const;
        const std::string& Marka() const;
        const std::string& Model() const;
        double Pojemnosc() const;
        int RokProdukcji() const;

        double Stawka() const;
        double Kwota() const;
};

#endif // RYZYKO_HPP_INCLUDED
