#include <iostream>
#include <set>
using namespace std;
//bool comp ( pair<int,int> a, pair<int,int> b ) {
//  if( a.first > b.first ) {
//    return true;
//  } else if( a.first == b.first && a.second >= b.second ) {
//    return true;
//  }
//  return false;
//}
int main() {
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  set< pair<int,int> > s; 
  int c = 0;
  for( int i = b; i <= y; i++ ) {
    int j = max( i+1, a );
    for( ; j <= x; j++ ) {
      pair<int,int> p;
      p.first = j; p.second = i;
      s.insert(p);
    }
  } 
  cout << s.size() << endl;
  for( set< pair<int,int> > :: iterator it = s.begin(); it != s.end(); it++ ) {
    cout << it->first << " " << it->second << endl;
  }
  return 0;
}
