#include <iostream>
using namespace std;
int foo( int * v, int n, int e, int e2 ) {
  bool b1 = false;
  bool b2 = false;
  int bgn = 1;
  int end = n;
  while( bgn <= end ) {
    int m = (bgn+end)/2;
    if( v[m] == e ) {
      b1 = true;
    }
    if( v[m] > e ) {
      end = m - 1;  
    }
    else {
      bgn = m + 1;
    }
  }
  bgn = 1;
  end = n;
  while( bgn <= end ) {
    int m = (bgn+end)/2;
    if( v[m] == e2 ) {
      b2 = true;
    }
    if( v[m] > e ) {
      end = m - 1;  
    }
    else {
      bgn = m + 1;
    }
  }
  if( b1 && b2 )
    return 1;
  return 0;
}
int main() {
  int x[200001];
  int n;
  while( cin >> n ) {
    int v[n];
    int amnt = 0;
    int sz;
    for( int i=0; i<n; i++ ) {
      cin >> x[i];
      x[i + n] = x[i];
      sz += x[i];
    }
    if( (sz % 3 != 0) ) {
      cout << "0" << endl;
      continue;
    }
    for(int i=0; i<n; i++) {
      v[0] = x[i];
      for( int j=1; j<n; j++ ) {
       v[j] = v[j-1] + x[i+j];   
      }
      int first = sz/3;
      int secnd = first + sz/3;
      amnt += foo( v, n, first, secnd);
    }
    cout << amnt << endl;
    cout << amnt/3 << endl;
  }
  return 0;
}
