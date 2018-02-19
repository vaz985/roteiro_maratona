#include<iostream>
using namespace std;
int main() {
  unsigned int n, l; 
  while( 1 ) {
    int v[1000001];
    cin >> n >> l;

    if( n == 0 && l == 0 )
      return 0;

    for( int i=1; i<=l; i++ )
      cin >> v[i];
    unsigned int min = -1; 
    for( int i=1; i<=l; i++ ) {
      unsigned int x = v[i] + n - 1;
      int s = 1;
      int e = l;
      int pos, t;
      while( s <= e ) {
        int m = (s+e)/2;
        if (v[m] == x) {
          pos = m;
          break;
        }
        if( v[m-1] < x && v[m] > x ) {
          pos = m-1;
          break;
        }
        else if( v[m] < x && v[m+1] > x ) {
          pos = m;
          break;
        }
        if( v[m] > x ) {
          e = m - 1;
        }
        else {
          s = m + 1;
        }
      }

      if( x == v[pos] ) {
        t = (v[pos]-v[i]) - (pos-i); 
      }
      else if( x > v[pos] ) {
        t = (v[pos]-v[i]) - (pos-i);
        t+= x - v[pos];
      }

      if( t < min ) 
        min = t;

      //cout << i << " " << x << " " << pos << endl << t << endl<< endl;
    }
    cout << min << endl;
  }
  return 0;
}
