#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main()
{
  while(1) {
    int n; cin >> n;
    if( n == 0 )
      exit(0);
    list<int> v;
    for( int i=0; i<n; i++ ) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    v.sort();
    for( auto it = v.begin(); it != v.end(); it++ ) {
      cout << *it << " ";
    }
    cout << endl;
    while( next_permutation( v.begin(), v.end() ) ) {
      for( auto it = v.begin(); it != v.end(); it++ ) {
        cout << *it << " ";
      }
      cout << endl;
    }
    v.clear();
    cout << endl;
  }
  return 0;
}
