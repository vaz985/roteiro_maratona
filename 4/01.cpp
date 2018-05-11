#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m; 
  int last = 0, last_last = 0;
  int charge = m;
  bool deu = true;
  cin >> last;
  for(int i=1; i<n; i++) {
    last_last = last;
    cin >> last; 
    //cout << charge << " " << last - last_last << endl;
    if(last - last_last <= charge) {
      charge -= (last-last_last); 
      charge += m;
    }
    else deu = false;
  }
  if(deu)
    cout << "S" << endl;
  else
    cout << "N" << endl;
  return 0;
}
