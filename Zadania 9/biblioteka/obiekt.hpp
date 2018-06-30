#ifndef OBIEKT_HPP_INCLUDED
#define OBIEKT_HPP_INCLUDED

#include <string>
#include "bio.hpp"

class Obiekt
{
    private:
        BIO bio_; // biblioteczny identyfikator
        std::string tytul_;

    public:
        Obiekt(BIO bio, std::string tytul)
            : bio_(bio), tytul_(tytul)
        {
        }

        virtual ~Obiekt(void) = default;

        auto napisBIO() -> std::string const
        {
            return bio_.Napis();
        }

};

#endif // OBIEKT_HPP_INCLUDED
