#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
int main() {
  int test_n = 1;
  while(1) {
    int n; cin >> n;
    if( n==0 ) break;
    cout << "Teste " << test_n++ << endl;
    vector< bitset<21> > v;
    bitset<21> b;
    for( int i=0; i<n; i++ ) {
      bitset<21> bs;
      while(1) {
        int x; cin >> x;
        if( x == 0 ) 
          break;
        bs.flip(x-1);
      }
      v.push_back(bs);
      //cout << i << " " << v[i] << endl;
    }
    //for( int i=1; i<=n; i++ ) 
    //  cout << v[i] << endl;
    int max = 0;
    for( int i=1; i < (1<<n); i++ ) {
      bitset<21> state = i;
      int amount = state.count();
      //cout << state << endl;
      //if( amount <= max ) continue;
      //cout << "state: " << state << endl;
      for( int j=0; j<n; j++ ) {
        if( state.test(j) ) {
          if( (state & v[j]).count() > 0 ) {
            amount = 0; 
            break;
          }
        }
      } 
      //cout << " " << r << endl;
      if( amount > max ) {
        max = amount;
        //cout << "max: " << state << endl;
      }
    }
    cout << max << endl << endl;
  }
  return 0;
}
