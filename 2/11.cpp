#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MAXN 2501
int n;
int main() {
  cin >> n;
  vector<ll> A(n);
  vector<ll> B(n);
  vector<ll> C(n);
  vector<ll> D(n);
  for(int i=0; i<n; i++) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    A[i] = a; B[i] = b; C[i] = c; D[i] = d;
  }
  for(int i=0; i<n; i++) {
    cout << A[i] << " " << B[i] << " " << C[i] << " " << D[i] << endl;
  } 
  
  return 0;
}
