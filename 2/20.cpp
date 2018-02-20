#include <iostream>
using namespace std;
int main() {
  int x[200001];
  int n;
  while( cin >> n ) {
    int v[n];
    int amnt = 0;
    for( int i=0; i<n; i++ ) {
      cin >> x[i];
      x[i + n] = x[i];
      amnt += x[i];
    }
    if( amnt == 0 || (amnt % 3 != 0) ) {
      cout << "0" << endl;
      continue;
    }
    amnt = 0;
    for(int i=0; i<n; i++) {
      v[0] = x[i];
      for( int j=1; j<n; j++ ) {
       v[j] = v[j-1] + x[i+j];   
      }
      
    }
    cout << "stop" << endl;
  }
  return 0;
}
