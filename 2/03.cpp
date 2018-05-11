//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define MAXN 10001
int main() {
  int n;
  vector<int> milk;
  cin >> n;
  for(int i=0; i<n; i++) {
    int x; cin >> x;
    milk.pb(x);
  }
  sort(milk.begin(), milk.end());
  cout << milk[milk.size()/2] << endl;
  return 0;
}

