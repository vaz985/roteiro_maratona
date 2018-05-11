#include <iostream>
#include <algorithm>
using namespace std;
void p( int * v, int n ) {  
  for( int i=0; i<n; i++ )
    cout << v[i] << " ";
  cout << endl;
}
int foo( int * v, int n, int e, int e2 ) {
  if( binary_search(v+1,v+1+n,e) && binary_search(v+1,v+1+n,e2) ) {
    return 1;
  }
  return 0;
}
int main() {
  int x[200001];
  int n;
  while( cin >> n ) {
    int v[n];
    int amnt = 0;
    int sz = 0;
    for( int i=0; i<n; i++ ) {
      cin >> x[i];
      x[i + n] = x[i];
      sz += x[i];
    }

    int first = sz/3;
    int secnd = first + sz/3;
    //if( (sz % 3 != 0) ) {
    //  cout << "0" << endl;
    //  continue;
    //}
    //cout << first << " " << secnd << endl;
    for(int i=0; i<n; i++) {
      v[0] = x[i];
      for( int j=1; j<n; j++ ) {
       v[j] = v[j-1] + x[i+j];   
      }
      //p(v,n);
      amnt += foo( v, n, first, secnd);
    }
    //cout << amnt << endl;
    cout << amnt/3 << endl;
  }
  return 0;
}
