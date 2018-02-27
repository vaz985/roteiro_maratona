#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main() {
  int T; cin >> T;
  while( T-- > 0 ) {
    int m, d;
    cin >> m >> d;
    vector< bitset<32> > v;
    for( int i=0; i<d; i++ ) {
      int n; cin >> n;
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
    unsigned int min_d = -1;
    for( int i=0; i<(1<<d); i++ ) {
      bitset<32> s;
      int amount = 0;
      for( int j=0; j<d; j++ ) {
        if( i & (1<<j) ) {
          s |= v[j];
          amount++;
        }
      }
      if( s.count() >= m && amount < min_d ) {
        min_d = amount;
      }
    }
    if( min_d == (unsigned int)(-1) ) {
      cout << "Desastre!" << endl;
    }
    else
      cout << min_d << endl;
  }
  return 0;
}
