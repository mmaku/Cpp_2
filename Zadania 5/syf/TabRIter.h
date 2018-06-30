#ifndef TABRITER_H_
#define TABRITER_H_

template<typename Value>
class TabRIter
{
  public:
    TabRIter(Value* ptr)
      : current_(ptr) { }
    Value& operator*(void)
    {
      Value* tmp = current_;
      return *--tmp;
    }
    Value* operator->(void)
    { 
      return &(operator*()); 
    }
    TabRIter& operator++()
    {
      --current_;
      return *this;
    }
    TabRIter operator++(int)
    {
      TabRIter tmp = *this;
      --current_;
      return tmp;
    }
    TabRIter& operator--()
    {
      ++current_;
      return *this;
    }
    TabRIter operator--(int)
    {
      TabRIter tmp = *this;
      ++current_;
      return tmp;
    }
    Value* Ptr(void) const
    {
      return current_;
    }

  private:
    Value* current_;
    Value* border_;
};

template<typename Value>
bool operator==(const TabRIter<Value>& a, const TabRIter<Value>& b)
{
  return (a.Ptr() == b.Ptr());
}

template<typename Value>
bool operator!=(const TabRIter<Value>& a, const TabRIter<Value>& b)
{
  return !(a == b);
}

template<typename Value>
TabRIter<Value> rbegin(Value* a, unsigned size)
{
  return TabRIter<Value>(a + size);
}

template<typename Value>
TabRIter<Value> rend(Value* a, unsigned size)
{
  return TabRIter<Value>(a);
}

#endif

