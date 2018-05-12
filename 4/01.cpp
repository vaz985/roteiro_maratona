#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
int main() {
  cin >> n >> m; 
  vector<ll> p(n+1);
  for(int i=0; i<n; i++) {
    cin >> p[i];
  }
  p[n] = (ll) 42195;
  //for(ll x : p)
  //  cout << x << " ";
  //cout << endl;
  ll charge = m;
  bool deu = true;
  for(int i=1; i<=n; i++) {
    if((p[i] - p[i-1]) > m) {
      deu = false;
      break;
    }
  }
  if(deu)
    cout << "S" << endl;
  else
    cout << "N" << endl;
  return 0;
}
