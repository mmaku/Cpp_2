#include <cmath>
#include <cstdio>
#include <iostream>

int reverseBits(int n)
{
    return ~n;
}


int main()
{
    int a, t;
    std::cin >> t;

    for(int i = 0; i < t; t++)
    {
        std::cin >> a;
        std::cout << reverseBits(a) << "\n";
    }
    return 0;
}
