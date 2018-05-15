#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001
int n;
vector<int> v(MAXN);
vector<int> prefix(MAXN);
int main() {
  while(1) {
    cin >> n;
    if(n==0) break;
    for(int i=0; i<n; i++) cin >> v[i];
    //prefix[0] = v[0];
    //for(int i=1; i<n; i++) prefix[i] = v[i] + prefix[i-1];
    int max_here = v[0], max_far = v[0];
    for(int i=1; i<n; i++) {
      max_here = max(v[i], max_here + v[i]);
      max_far  = max(max_far, max_here);
    }
    if(max_far>0) {
      cout << "The maximum winning streak is " << max_far;
    }
    else {
      cout << "Losing streak";
    }
    cout << "." << endl;
  }
  return 0;
}
