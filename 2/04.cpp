#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &v) {
  for(int x : v)
    cout << x << " ";
  cout << endl;
}
bool f = true;
int main() {
  while(1) {
    int n; cin >> n;
    if(n==0) break;
    else if(!f) cout << endl;
    f = false;
    vector<int> v(n);
    for(int i=0; i<n; i++) 
      cin >> v[i];
    sort(v.begin(), v.end());
    print(v);
    int sz = v.size();
    while(1) {
      bool last = true;
      int pos;
      int gtk = sz-1;
      for(pos=sz-2; pos>=0; pos--) {
        if(v[pos] < v[pos+1]) {
          last = false;
          for(;gtk>=pos;gtk--)
            if(v[pos] < v[gtk])
              break;
          //cout << v[pos]
          swap(v[pos], v[gtk]);
          reverse(v.begin() + (pos+1), v.end());
          break;
        }
      }
      if(last)  break;
      print(v);
    }
  }
  return 0;
}
