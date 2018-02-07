#include <iostream>
#include <utility>
using namespace std;
int main()
{
  int n = 15;
  pair<int,int> g[16];
  for( int i=1; i<=15; i++ ) {
    cin >> g[i].first >> g[i].second;
  }
  cout << endl;
  return 0;
}
