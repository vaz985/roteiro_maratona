#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int a, b;
int main(){
  while(1) {
    cin >> a >> b;
    if(a==0 && b==0)  break;
    int menor_a = inf;
    vector<int> b_v(b);
    for(int i=0; i<a; i++) {
      int x; cin >> x;
      menor_a = min(menor_a, x);
    }
    for(int i=0; i<b; i++) 
      cin >> b_v[i];
    sort(b_v.begin(), b_v.end());
    if(menor_a < b_v[1])
      cout << "Y" << endl;
    else 
      cout << "N" << endl;
  }
  return 0;
}
