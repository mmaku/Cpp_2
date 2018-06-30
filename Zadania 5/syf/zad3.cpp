#include <cassert>
#include <iostream>
#include <vector>
#include "Grid.h"
#include "TabRIter.h"

void test_TabRIter(void)
{
  Grid g[] = {{1,2},{3,4},{5,6},{7,8},{9,0}};
  auto b = rbegin(g,5);
  assert(b->X()==9);
  assert(b->Y()==0);
  auto c = b++;
  assert(c->X()==9);
  assert(c->Y()==0);
  assert(b->X()==7);
  assert(b->Y()==8);
  assert(--b==c);
  auto d = rend(g,5);
  d--;
  assert(d->X()==1);
  assert(++d==rend(g,5));
  std::vector<int> v;
  for(auto i=rbegin(g,5); i!=rend(g,5); ++i)
    v.push_back((*i).X());
  assert((v==std::vector<int>{9,7,5,3,1}));
  std::cerr << "Test ok\n";
}

int main(void)
{
  test_TabRIter();;
  return 0;
}
