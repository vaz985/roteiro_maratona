#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  int testNo = 1;
  while(1) {
    cin >> n;
    if(!n) break; 
    cout << "Teste " << testNo << endl;
    if(testNo++>1) cout << endl;
    int i=0, j=0, k=0, l=0;
    i = (n/50);
    n -= 50*i;
    j = (n/10);
    n -= 10*j;
    k = (n/5);
    n -= 5*k;
    l = (n/1);
    n -= 1*l;
    cout << i << " " << j << " " << k << " " << l << endl;
  } 
  return 0;
}
