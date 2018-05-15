#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MAXN 10001
using namespace std;
int n;
int mm[MAXN];
vector< pair<int,int> > v;
bool comp( pair<int,int> &a,pair<int,int> &b) {
  if(a.second<=b.second)
    return true;
  return false;
}  
int main() {
  cin >> n;
  memset(mm, 0, sizeof(mm));
  for(int i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    v.pb(mp(x,y));
  }
  sort(v.begin(), v.end(), comp);
  int count = 1;
  int end = v[0].second;
  for(int i=1; i<n; i++) {
    if(v[i].first >= end) {
      end = v[i].second;
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
