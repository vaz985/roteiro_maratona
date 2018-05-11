#include <bits/stdc++.h>
#define buff ios::sync_with_stdio(false);
#define ll long long
using namespace std;
int main() { buff
  int n, q;
  scanf("%d %d",&n,&q);
  vector<ll> v(n);
  for(int i=0; i<n; i++) {
    scanf("%lld",&v[i]);
  }
  for(int i=0; i<q; i++) {
    ll x; cin >> x;
    vector<ll> :: iterator it = lower_bound(v.begin(), v.end(), x);
    if( x != v[ it-v.begin() ] )
      cout << -1 << endl;
    else {
      cout << *(it-1) << " " << *it << endl;
      while( *(it-1) == *it )
        it--;
      printf("%d\n", it-v.begin());
    }
  }
  return 0;
}
