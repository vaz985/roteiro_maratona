#include <bits/stdc++.h>
using namespace std;
#define MAXN 101
#define MAXVAL 10101
int x, y, n;
int v[MAXN];
bool mm[MAXN][MAXVAL];
void dp(int sum) {
  for(int i=0; i<=n;i++) {
    mm[i][0] = true;
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=sum; j++) {
      if(j<v[i-1]) 
        mm[i][j] = mm[i-1][j];
      else
        mm[i][j] = mm[i-1][j] || mm[i-1][j-v[i-1]];
    }
  }
}
int main() {
  int TstNo = 1;
  while(1) {
    cin >> x >> y >> n; 
    if(n==0) break;
    if(TstNo>1) cout << endl;
    memset(mm, false, sizeof(mm));
    int acc = 0;
    for(int i=0; i<n; i++) {
      cin >> v[i];
      acc += v[i];
    }
    int part = acc + x + y;
    dp(part/2 - x);
    for(int i=0; i<n; i++) {
      for(int j=1; j<=(part/2)-x; j++) {
        cout << mm[i][j] << " ";
      }
      cout << endl;
    }
    cout << "Teste " << TstNo++ << endl;
  }
  return 0;
}
