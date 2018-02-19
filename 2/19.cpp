#include<iostream>
using namespace std;
//int fun( int s, int * v, int n ) {
//  int amnt = 0;
//   
//  return amnt;
//}
int main() {
  unsigned int n, l; 
  while( 1 ) {
    int v[1000001];
    cin >> n >> l;

    if( n == 0 && l == 0 )
      return 0;

    for( int i=1; i<=l; i++ )
      cin >> v[i];
    
    for( int i=1; i<=l; i++ ) {
      int e = v[i] + n - 1;
    }
  }
  return 0;
}
