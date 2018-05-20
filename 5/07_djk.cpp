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
vii adj[MAX];
int n, m;
vi saida;
int start;
void setup() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(mp[i][j]==2) continue;
      // up i,j-1
      if(j-1 >= 0 && mp[i][j-1]!=2) {
        adj[pos(i,j)].pb(ii(pos(i,j-1),1));
      }
      // dw i,j+1
      if(j+1 < m && mp[i][j+1]!=2) {
        adj[pos(i,j)].pb(ii(pos(i,j+1),1));
      }
      // lf i-1,j
      if(i-1 >= 0 && mp[i-1][j]!=2) {
        adj[pos(i,j)].pb(ii(pos(i-1,j),1));
      }
      // rt i+1,j
      if(i+1 < n && mp[i+1][j]!=2) {
        adj[pos(i,j)].pb(ii(pos(i+1,j),1));
      }
    }
  }
}
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
  priority_queue< ii, vii, greater<ii> > pq; pq.push(ii(0,start)); 
  while(!pq.empty()) {
    ii front = pq.top(); pq.pop(); 
    int d = front.first, u = front.second;
    if(d>dist[u]) continue;
    for(int j=0; j<adj[u].size(); j++) {
      ii v = adj[u][j];
      if(dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;
        pq.push(ii(dist[v.first], v.first));
      }
    }
  }
  int resp = inf;
  for(int i=0; i<saida.size(); i++) {
    resp = min(resp, dist[saida[i]]);
  }
  cout << resp << endl;
  return 0;
}
