#ifndef PUNKT_HPP
#define PUNKT_HPP

class Punkt
{
    private:
        double x_;
        double y_;

    public:
        Punkt(double x=0.0, double y=0.0);
        double X() const;
        double Y() const;
};

void test_punkt();

#endif // PUNKT_HPP
