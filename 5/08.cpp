#include <bits/stdc++.h>
using namespace std;
#define MAXC 5001
#define pb push_back
#define vi vector<int>
int c, r;
map<string, int> mp;
vi adj[MAXC];
int bfs(int start) {
  bool visited[c]; 
  memset(visited, false, sizeof(visited));
  stack<int> s;
  s.push(start);
  int count = 1;
  visited[start] = true;
  while(!s.empty()) {
    int u = s.top(); s.pop();
    for(int j=0; j<adj[u].size(); j++) {
      int v = adj[u][j];
      if(!visited[v]) {
        visited[v] = true;
        s.push(v);
        count++;
      }
    }
  }
  return count;
}
int main() {
  while(1) {
    cin >> c >> r;
    if(c==0) break;
    mp.clear();
    for(int i=0; i<c; i++) {
      adj[i].resize(0);
    }
    for(int i=0; i<c; i++) {
      string s; cin >> s;
      mp[s] = i;
    }
    for(int i=0; i<r; i++) {
      string x, y; cin >> x >> y;
      adj[ mp[x] ].pb( mp[y] );	
      adj[ mp[y] ].pb( mp[x] );	
    }
    int max_ = 0;
    for(int i=0; i<c; i++) {
      max_ = max(max_, bfs(i));
    }
    cout << max_ << endl;
 
  }
  return 0;
}
