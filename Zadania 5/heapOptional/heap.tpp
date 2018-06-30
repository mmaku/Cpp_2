#include "heap.hpp"
#include "data.hpp"

#include <cassert>
#include <iostream>

template<typename Value>
class HeapOptional
{
    private:
        Value* wsk_;

    public:

        HeapOptional(Value* wsk=nullptr)
          : wsk_(wsk)
        {}

        ~HeapOptional()  //dekonstruktor
        {
            delete wsk_;
        //    wsk_=nullptr;
        }

        Value& operator*()
        {
            return *wsk_;
        }

        Value* operator->()
        {
          return &(operator*());
        }

        HeapOptional& operator=(HeapOptional&& a) noexcept
        {
          return *this;
        }

        const HeapOptional& operator=(const HeapOptional& a)
        {
            delete this->wsk_;
            Value* V=new Value(a.wsk_);
            this->wsk_=V;

            return *this;
        }

        HeapOptional(const HeapOptional& a)
        : wsk_(new Value)
        {
            *wsk_=*(a.wsk_);
        }

        operator bool() const
        {
            return (wsk_ != nullptr);
        }
};

void test_HeapOptional()
{
    HeapOptional<Data> d1(new Data(17,11,2014));
    assert(d1);
    assert(d1->Rok()==2014);
    assert(d1->Miesiac()==11);
    assert(d1->Dzien()==17);

    HeapOptional<Data> d2(d1);
    HeapOptional<Data> d3;
    assert(!d3);
    d3=d1;
    HeapOptional<Data> d4=d1;

    assert((*d2).Rok()==2014);  // konstruktora kopiujacy
    assert((*d2).Miesiac()==11);
    assert((*d2).Dzien()==17);

    assert(d3->Rok()==2014);    // operator przypisania
    assert(d3->Miesiac()==11);
    assert(d3->Dzien()==17);

    assert(d4->Rok()==2014);
    assert(d4->Miesiac()==11);
    assert(d4->Dzien()==17);

    std::cerr<<"test_heapOptional ok\n";
}
