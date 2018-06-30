#ifndef GIELDA_HPP
#define GIELDA_HPP

class gielda
{
    private:
        std::string nazwaGieldy_;
        notowania spolki_;

    public:
        gielda(std::string nazwaGieldy, notowania spolki);
        std::string nazwa() const;
        std::string nazwaSpolki(unsigned int indeks) const;
        unsigned int iloscSpolek() const;
        para operator[](int indeks) const;
        para operator[](int& indeks);
        void dodajSpolke(para spolka);
};


#endif // GIELDA_HPP
