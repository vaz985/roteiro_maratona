#include <iostream>
using namespace std;
int n;
int main() {
  while(1) {
    cin >> n; 
    unsigned int v[101] = {0};
    int max = 0;
    if( n == 0 ) 
     break;
    for( int i=1; i<=n; i++ ) {
      for( int j=1; j<=n; j++ ) {
        int x;
        cin >> x;
        if( x == 1 ) {
          v[j]++;
        }
      }
    } 
    for( int i=1; i<=n; i++ ) {
      if( v[i] > max )
        max = v[i];
    }
    cout << max << endl;
  }
  return 0;
}
