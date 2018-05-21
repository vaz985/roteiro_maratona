#include <bits/stdc++.h>
using namespace std;
#define MAXN 31
#define vi vector<int>
int n;
list<string> nms;
vi adj[MAXN];
bool visited[MAXN];
int color[MAXN];
map<string,int> m;
map<int,string> vert;
void dfs(int pos) {
  for(int i=0; i<adj[pos].size(); i++)
    if(!visited[adj[pos][i]])
      dfs(adj[pos][i]);
  visited[pos] = true;
  nms.push_back( vert[pos] );
}
bool aux(int u) {
  color[u] = 1;
  for(int i=0; i<adj[u].size(); i++) {
    int v = adj[u][i];
    if(color[v] == 1)
      return true;
    if(color[v] == 0 && aux(v))
      return true;
  }
  color[u] = 2;
  return false;
}
bool cicle() {
  memset(color, 0, sizeof(color));
  for(int i=0; i<n; i++) 
    if(color[i] == 0)
      if(aux(i))
        return true;

  return false;
}
int main() {
  int TestNo = 1;
  while(1) {
    cin >> n;
    if(!n) break;
    if(TestNo>1) cout << endl;
    cout << "Teste " << TestNo++ << endl;
    memset(visited, false, sizeof(visited));
    nms.clear();
    m.clear();
    vert.clear();
    for(int i=0; i<n; i++) {
      string s; cin >> s;
      m[s] = i;
      vert[i] = s;
      adj[i].resize(0);
    }
    for(int i=0; i<n; i++) {
      string s; cin >> s;
      int r; cin >> r;
      for(int j=0; j<r; j++) {
        string s2; cin >> s2;
        adj[m[s]].push_back(m[s2]);
      }
    }
    if(cicle){ 
      cout << "impossivel" << endl;
      continue;
    }
    for(int i=0; i<n; i++) {
      if(visited[i]) continue;
      dfs(i);
    }
    auto it = nms.begin();
    for(int i=0; i<n; i++) {
      cout << *it << " ";
      it++;
    }
    cout << endl;
  } 
  return 0;
}
