#include <iostream>
#include <list>
#include <vector>
#include <bitset>
using namespace std;
bool comp( bitset<32> a, bitset<32> b ) {
  if( a.count() >= b.count() )
    return true;
  return false;
}

int main() {
  int T; cin >> T;
  while( T-- > 0 ) {
    int m, d;
    cin >> m >> d;
    list< bitset<32> > l;
    for( int i=0; i<d; i++ ) {
      int n; cin >> n;
      if( n == 0 ) 
        continue;
      bitset<32> b;
      for( int j=0; j<n; j++ ) {
        int x; cin >> x;
        b.flip(x);  
      }
      l.push_back(b);
    }
    if( m == 0 ) {
      cout << "0" << endl;
      continue;
    }
    l.sort(comp);
    unsigned int count = 1;
    bitset<32> s = l.front(); l.pop_front();
    cout << s << endl << endl;
    while( !l.empty() ) {
      if( s.count() >= m ) {
        break;
      }
      list< bitset<32> > :: iterator rm;
      unsigned int max = 0;
      for( list< bitset<32> > :: iterator it = l.begin(); it != l.end(); it++ ) {
        if( ((*it).count() -  (s&*it).count()) > max ) {
          rm = it;
          max = ((*it).count() - (s&*it).count());
        }
      }
      s |= (*rm);
      l.erase(rm);
      count++;
    }
    if( s.count() < m ) {
      cout << "Desastre!" << endl;
    } else {
      cout << count << endl;
    }
  }
  return 0;
}
// Mudar para uma abordagem gulosa do set cover
