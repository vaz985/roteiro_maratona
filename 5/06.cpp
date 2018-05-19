#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 101
#define inf 0x3f3f3f3f
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
int n;
ll adj[MAXN][MAXN];
int main() { _
  int TestNo = 1;
  while(1) {
    cin >> n;
    if(n==0) break;
    if(TestNo>1) cout << endl;
    memset(adj, inf, sizeof(adj));
    for(int i=1; i<n; i++) {
      int x, y; cin >> x >> y;
      adj[x][y] = 1; 
      adj[y][x] = 1; 
    }
    for(int i=1; i<=n; i++) 
      adj[i][i] = 0;
        
    for(int k=1; k<=n; k++) 
      for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++) 
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    ll min_  = inf;
    int min_line = 0;
    for(int i=1; i<=n; i++) {
      ll line_max = 0;
      for(int j=1; j<=n; j++) {
        if(adj[i][j] < inf) line_max = max(adj[i][j], line_max);
      }
      if(line_max < min_) {
        min_ = line_max;
        min_line = i;
      }
    }
    //for(int i=1; i<=n; i++) {
    //  for(int j=1; j<=n; j++) {
    //    cout << adj[i][j] << " ";
    //  }
    //  cout << endl; 
    //}
    cout << "Teste " << TestNo++ << endl;
    cout << min_line << endl;
  }
  return 0;
}
