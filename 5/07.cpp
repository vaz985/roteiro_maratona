#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define pb push_back
#define ii pair<int,int>
#define vi  vector<int>
#define vii vector<ii>
int mp[MAX][MAX];
int n, m;
vii saida;
int main() {
  cin >> n >> m; 
  memset(mp, inf, sizeof(mp));
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      int x; cin >> x;
      if(x==0) {
        saida.pb(ii(x,y));
      }
      if(x==0 || x==1) mp[i][j] = 1; 
    }
  }
  return 0;
}
