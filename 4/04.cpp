#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf 0x3f3f3f3f
#define MAXF 51
#define MAXC 1001
using namespace std;
int c, f;
int v[MAXF];
int w[MAXF];
int mem[MAXF][MAXC];
int val(int id, int rw) {
  if(mem[id][rw] > 0) return mem[id][rw];
  if(id>=f) return 0;
  if(rw<=0) return 0;
  if(w[id]>rw) return val(id+1,rw);
  return mem[id][rw] = max( val(id+1,rw), v[id] + val(id+1,rw - w[id]) );
}
int main() {
  int testNo = 1;
  while(1) {
    cin >> c >> f;
    if(c==0) break;
    if(testNo>1) cout << endl;
    cout << "Teste " << testNo << endl;
    memset(mem,0,sizeof(mem));
    for(int i=0; i<f; i++) {
      cin >> w[i] >> v[i];
    }
    //int max_ = 0;
    //for(int i=0; i<f; i++) {
    //  max_ = max(max_, val(v[i], c));
    //}
    cout << val(0,c) << endl;
    testNo++;
  } 
  return 0;
}
