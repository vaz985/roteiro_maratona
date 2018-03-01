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
    bitset<21> b; v.push_back(b);
    for( int i=1; i<=n; i++ ) {
      bitset<21> bs;
      while(1) {
        int x; cin >> x;
        if( x == 0 ) 
          break;
        bs.flip(x);
      }
      v.push_back(bs);
    }
    //for( int i=1; i<=n; i++ ) 
    //  cout << v[i] << endl;
    int max = 0;
    for( int i=1; i < (1<<n); i++ ) {
      int amount = 0;
      bitset<21> state = i;
      cout << state << endl;
      bool stop = false;
      for( int j=1; j<=n && stop==false; j++ ) {
        if( state.test(j) ) {
          amount++;
          for( int k=1; k<=n; k++ ) {
            if( state.test(k) && v[j].test(k) ) {
              stop = true; 
              amount = 0;
            }
          }
        } 
      }
      if( amount > max ) {
        max = amount;
        cout << "melhorou" << endl;
      }
    }
    cout << max << endl;
    break;
  }
  return 0;
}
