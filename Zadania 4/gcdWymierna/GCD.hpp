#ifndef GCD_HPP
#define GCD_HPP

template <class klasa>
klasa GCD(klasa a, klasa b) // ma sens tylko dla typow calkowitoliczbowych
{
    klasa c = 0;
    while ( a != 0 )
    {
        c = a;
        a = b%a;
        b = c;
    }
    return b;
}

auto test_GCD() -> void;

#endif // GCD_HPP
