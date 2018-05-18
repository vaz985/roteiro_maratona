#include <bits/stdc++.h>
#define MAXN 101
#define MAXM ((MAXN*(MAXN-1))/2)+1
#define pb push_back
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int n, m;
int clr[MAXN];
vector<int> adj[MAXN];
int main() { _
  int InstNo = 1;
  while(1) {
    cin >> n >> m;
    if(not cin) break;
    if(InstNo>1) cout << endl;
    for(int i=0; i<=n; i++) 
      adj[i].resize(0);
    for(int i=0; i<m; i++) {
      int x, y;
      cin >> x >> y; 
      adj[x].pb(y);
      adj[y].pb(x);
    }
    bool sim = true;
    queue<int> q; q.push(1);
    memset(clr, -1, sizeof(clr));
    clr[1] = 0;
    while(!q.empty() && sim) {
      int x = q.front(); q.pop();
      for(int i=0; i<adj[x].size(); i++) {
        int y = adj[x][i];
        if(clr[y] == -1) {
          clr[y] = 1 - clr[x]; 
          q.push(y);
        }
        else if(clr[y] == clr[x]){
          sim = false;
          break;
        }
      } 
    }
    cout << "Instancia " << InstNo++ << endl;
    if(sim) 
      cout << "sim" << endl;
    else 
     cout << "nao" << endl; 
  }
  return 0;
}
