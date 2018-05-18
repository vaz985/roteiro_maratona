#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 51
#define ii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
int c, e, l, p;
vector<ii> adj[MAXN];
int dist[MAXN];
int main() { _
  int TestNo = 1;
  while(1) {
    cin >> c >> e >> l >> p;
    if(c==0) break;
    if(TestNo>1) cout << endl;
    for(int i=0; i<=c; i++) {
      adj[i].resize(0);  
      dist[i] = inf;
    }
    for(int i=0; i<e; i++) {
      int x, y; cin >> x >> y;
      adj[x].pb(ii(y,1));
      adj[y].pb(ii(x,1));
    }
    dist[l] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,l));
    while(!pq.empty()) {
      ii front = pq.top(); pq.pop(); 
      int d = front.first, u = front.second;
      if(d > dist[u]) continue;
      for(int j=0; j<adj[u].size(); j++) {
        ii v = adj[u][j];
        if(dist[u] + v.second < dist[v.first]) {
          dist[v.first] = dist[u] + v.second;
          pq.push(ii(dist[v.first], v.first));
        }
      }
    }
    cout << "Teste " << TestNo++ << endl;
    for(int i=1; i<=c; i++) {
      if(i!=l && dist[i] <= p)
        cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
