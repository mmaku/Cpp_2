#include "punkt.hpp"

#include <iostream>
#include <cassert>

Punkt::Punkt(double x, double y)
    : x_(x), y_(y)
{}

double Punkt::X() const
{
    return x_;
}

double Punkt::Y() const
{
    return y_;
}

void test_punkt()
{
    Punkt A;
    Punkt B(1.0,1.0);
    Punkt C(-1.0,-1.0);
    assert(A.X()==0.0);
    assert(A.Y()==0.0);
    assert(B.X()==-C.X());
    assert(B.Y()==-C.Y());

    std::cerr << "testPunkt ok\n";
}
