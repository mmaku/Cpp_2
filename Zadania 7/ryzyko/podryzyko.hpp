#ifndef PODRYZYKO_HPP_INCLUDED
#define PODRYZYKO_HPP_INCLUDED

class Podryzyko
{
    protected:
        double stawka_ = 0.0;

    public:
        Podryzyko(double stawka)
            : stawka_(stawka)
        {
        }

        double Stawka() const
        {
          return stawka_;
        }

        virtual ~Podryzyko() = default;
};


#endif // PODRYZYKO_HPP_INCLUDED
