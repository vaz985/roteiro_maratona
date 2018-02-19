#include <iostream>
using namespace std;
int main() {
  int x[200001];
  int n;
  while( cin >> n ) {
    for( int i=0; i<n; i++ ) {
      cin >> x[i];
      //x[i + n] = x[i];
    }
  }
  return 0;
}
