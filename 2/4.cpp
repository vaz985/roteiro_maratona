#include <iostream>
#include <list>
using namespace std;
int main()
{
  while(1) {
    int A, D;
    list<int> a, b;
    cin >> A >> D;
    for( int i=0; i<A; i++ ) {
      int x; cin >> x;
      a.push_back(x);
    }
    for( int i=0; i<D; i++ ) {
      int x; cin >> x;
      b.push_back(x);
    }
    a.sort(); b.sort();

  }
  return 0;
}
