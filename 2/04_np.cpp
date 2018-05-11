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
    while(next_permutation(v.begin(), v.end()))
      print(v);
  }
  return 0;
}
