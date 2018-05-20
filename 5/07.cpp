#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define pb push_back
#define ii pair<int,int>
#define vi  vector<int>
#define vii vector<ii>
#define pos(x,y) (((y)*m) + (x))
#define inf 0x3f3f3f3f
int mp[MAX][MAX];
int dist[MAX];
vi adj[MAX];
int n, m;
vi saida;
int start;
void setup();
int main() {
  cin >> n >> m; 
  memset(mp, 2, sizeof(mp));
  memset(dist, inf, sizeof(dist));
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      int x; cin >> x;
      if(x==0) {
        saida.pb(pos(i,j));
      }
      if(x==3) {
        start = pos(i,j);
        dist[pos(i,j)] = 0;
      }
      mp[i][j] = x;
    }
  }
  setup();
  queue<int> q;
  q.push(start);
  while(!q.empty()) {
    int u = q.front(); q.pop();  
    for(int j=0; j<adj[u].size(); j++) {
      int v = adj[u][j];
      if(dist[v] == inf) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  int min_= inf;
  for(int i=0; i<saida.size(); i++) {
    min_ = min(min_, dist[saida[i]]); 
  }
  cout << min_ << endl;
  return 0;
}



void setup() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(mp[i][j]==2) continue;
      // up i,j-1
      if(j-1 >= 0 && mp[i][j-1]!=2) {
        adj[pos(i,j)].pb(pos(i,j-1));
      }
      // dw i,j+1
      if(j+1 < m && mp[i][j+1]!=2) {
        adj[pos(i,j)].pb(pos(i,j+1));
      }
      // lf i-1,j
      if(i-1 >= 0 && mp[i-1][j]!=2) {
        adj[pos(i,j)].pb(pos(i-1,j));
      }
      // rt i+1,j
      if(i+1 < n && mp[i+1][j]!=2) {
        adj[pos(i,j)].pb(pos(i+1,j));
      }
    }
  }
}
