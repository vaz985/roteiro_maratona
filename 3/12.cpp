#include <iostream>
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
    vector< bitset<32> > v;
    for( int i=0; i<d; i++ ) {
      int n; cin >> n;
      if( n == 0 ) 
        continue;
      bitset<32> b;
      for( int j=0; j<n; j++ ) {
        int x; cin >> x;
        b.flip(x);  
      }
      v.push_back(b);
    }
    if( m == 0 ) {
      cout << "0" << endl;
      continue;
    }
    unsigned int min = -1;
    for( int it = 0; it < d; it++ ) {
      bitset<32> s = v[it];
      unsigned int count = 1;
      while( s.count() < m && count < d ) {
        int idx = it; int max = 0;
        for( int it2 = 0; it2 < d; it2++ ) {
          if( ( v[it2].count() - (s&v[it2]).count() ) > max && it != it2 ) {
            idx = it2;
            max = ( v[it2].count() - (s&v[it2]).count() );
          }
        } 
        s |= v[idx];
        count++;
      }
      if( s.count() >= m && count < min ) {
        min = count;
      }
      //cout << s << endl;
    } 
    if( min > d ) 
      cout << "Desastre!" << endl;
    else
      cout << min << endl;
  }
  return 0;
}
// Mudar para uma abordagem gulosa do set cover
