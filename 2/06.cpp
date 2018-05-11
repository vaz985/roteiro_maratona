#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
bool comp(pair<string,int> &a, pair<string,int> &b) {
  if(a.second > b.second)
    return true;
  if(a.second==b.second)
    if(a.first<b.first)
      return true;
  return false;
}
int main() {
  int inst = 1;
  while(1) {
    int n;
    cin >> n;
    if(cin.eof())
      break;
    vector< pair<string,int> > v(n);
    for(int i=0; i<n; i++) {
      string s; int x;
      cin >> s >> x;
      v[i] = mp(s,x);
    }
    sort(v.begin(), v.end(), comp);
    //for( pair<string,int> p : v )
    //  cout << p.first << " " << p.second << endl;
    cout << "Instancia " << inst++ << endl;
    cout << v[n-1].first << endl; 
  }
  return 0;
}
