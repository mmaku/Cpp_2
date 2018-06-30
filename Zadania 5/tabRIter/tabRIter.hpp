#ifndef TABRITER_HPP_INCLUDED
#define TABRITER_HPP_INCLUDED

template<typename parametr>
class tabRIter
{
    private:
        parametr* wskaznik_;  // zmienna wskaznikowa do typu parametr

    public:
        tabRIter(parametr* wskaznik)
            : wskaznik_(wskaznik)
        {}

        parametr& operator*()  // dereference
        {
            parametr* temp = wskaznik_;
            return *--temp;
        }

        parametr* operator->() // adress-of operator
        {
            return &(operator*());
        }

        tabRIter& operator++()  // pre-increment
        {
            --wskaznik_;
            return *this;
        }

        tabRIter operator++(int)  // post-increment
        {
            tabRIter temp = *this;
            --wskaznik_;
            return temp;
        }

        tabRIter& operator--()
        {
            ++wskaznik_;
            return *this;
        }

        tabRIter operator--(int)
        {
            tabRIter temp = *this;
            ++wskaznik_;
            return temp;
        }

        parametr* wsk() const  // zwraca po prostu wskaznik
        {
            return wskaznik_;
        }
};

template<typename parametr>
bool operator==(const tabRIter<parametr>& a, const tabRIter<parametr>& b)
{
  return (a.wsk() == b.wsk());
}

template<typename parametr>
bool operator!=(const tabRIter<parametr>& a, const tabRIter<parametr>& b)
{
  return !(a == b);
}

template<typename parametr>
tabRIter<parametr> rbegin(parametr* a, unsigned size)
{
  return tabRIter<parametr>(a + size);
}

template<typename parametr>
tabRIter<parametr> rend(parametr* a, unsigned size)
{
  return tabRIter<parametr>(a);
}

#endif // TABRITER_HPP_INCLUDED
