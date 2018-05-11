#include <iostream>
#include <list>
#include <vector>
#include <bitset>
using namespace std;
struct best_sol {
  bitset<32> best_s;
  int d_count;
};
struct best_sol bs;
void f( vector<bitset<32> > v, bitset<32> s, int d, int m ) {

  if( s.count() >= m && d < bs.d_count ) {
    bs.best_s = s;
    bs.d_count = d; 
  }

  if( v.size() == 0 ) {
    return;
  }
  else {
    for( int i=0; i<v.size(); i++ ) {
      if( (v[i].count() - (s&v[i]).count()) > 0 ) {
      //if( ( (*(v.begin()+i)).count() - (s&*(v.begin()+i)).count()) > 0 ) {
        bitset<32> s2 = s | *(v.begin() + i);
        vector< bitset<32> > v2 = v; v2.erase(v2.begin() + i);
        f( v2, s2, d+1, m );
      }
    } 
  }  

}
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
    bs.d_count = d+1;
    for( int i=0; i<d; i++ ) {
      bitset<32> s = *(v.begin()+i); 
      vector< bitset<32> > v2 = v; v2.erase(v2.begin()+i);
      f( v2, s, 1, m );
    }
    if( bs.best_s.count() >= m && bs.d_count <= d ) {
      cout << bs.d_count << endl;
    }
    else {
      cout << "Desastre!" << endl;
    }
  }
  return 0;
}
