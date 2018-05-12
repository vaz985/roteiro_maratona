#include <bits/stdc++.h>
using namespace std;
#define MAXN 101
#define MAXM 50001
#define inf 0x3f3f3f3f
int m, n;
vector<int> v;
vector<int> mm;
int change(int x){
  if(x == 0) return 0;
  if(mm[x] != MAXM) {
    return mm[x]; 
  }
  int min_ = MAXM;
  for(int coinVal : v) {
    if(coinVal>x) break;
    min_ = min(min_, change(x - coinVal));
  }
  return  mm[x] = 1 + min_;
}
int main() {
  while(1) {
    cin >> m;
    if(m==0) break;
    cin >> n;
    v.assign(n,0);
    mm.assign(m+1,MAXM);
    for(int i=0; i<n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int result = change(m);
    if(result==MAXM+1)
      cout << "Impossivel" << endl;
    else
      cout << result << endl;
  }
  return 0;
}
