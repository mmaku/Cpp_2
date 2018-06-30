#ifndef FIRMA_H_
#define FIRMA_H_

#include <string>
#include "podatnik.hpp"
#include "nip.hpp"

class Firma
    : public Podatnik
{
    private:
        std::string nazwa_;
        NIP nip_;

    public:
        Firma(std::string nazwa, std::string nip);
        std::string Dane(void) override final;
};

#endif /* FIRMA_H_ */
