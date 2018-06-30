#include <iostream>
#include <sstream>
#include <assert.h>

#include "list.cpp"

using namespace MYown;

auto testList() -> void;

int main()
{
   testList();
    return 0;
}

auto testList() -> void
{
    TsingleList<int> test1;
    TsingleList<int> test2;
    TsingleList<int> test3;

    for(int i = 1; i <= 10; i++)
        test1.push_back(i);

    for(int i = 5; i >= 1; i--)
        test2.push_front(i);

    for(int i = 10; i >= 1; i--)
        test3.push_front(i);

    assert(test1 == test3);
    assert(test2 != test3);

    {
        TsingleList<int> test4;
        for(int i = 5; i >= 1; i--)
            test4.push_front(i);
        test1 = test4;
    }

    assert(test1 == test2);
    assert(test1 != test3);

    swap(test3, test1);
    assert(test2 == test3);
    assert(test1 != test3);

    std::ostringstream tmp1;
    std::ostringstream tmp2;
    tmp1 << "1,2,3,4,5";
    tmp2 << test3;
    assert(tmp1.str() == tmp2.str());

    TsingleList<int>::iterator i = test3.begin();
    i++;
//    ++i;
    i.erase();
    std::cout << "\n" << test3;


    std::cout << "testList ok!\n";
}
