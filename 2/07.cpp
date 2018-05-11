#include <bits/stdc++.h>
using namespace std;
struct cont {
  int i;
  int init_p;
  int p;
  queue<int> wins;
};
int main() {
  int T; cin >> T;
  while( (T--) > 0 ) {
    int n, k;
    cin >> n >> k;
    int c_num = pow(2,n);
    queue<cont> q;
    for( int i=1; i<=c_num; i++ ) {
      struct cont c;
      cin >> c.init_p;
      c.p = c.init_p;
      c.i = i;
      q.push(c);
    }
    for( int i=n; i>0; i-- ) {
      for( int j=pow(2,i); j>0; j-=2 ) {
        struct cont a, b;
        a = q.front(); q.pop();
        b = q.front(); q.pop();
        if( a.p >= b.p ) {
          a.wins.push(b.i); 
          a.p = min( a.init_p, (a.p-b.p+k) );
          q.push(a);
        }
        else {
          b.wins.push(a.i); 
          b.p = min( b.init_p, (b.p-a.p+k) );
          q.push(b);
        }
      }
    }
    cout << q.front().i << endl;
    while( !q.front().wins.empty() ) {
      cout << q.front().wins.front();
      q.front().wins.pop();
      if( !q.front().wins.empty() ) 
        cout << " ";
    }
    cout << endl;
  } 
  return 0;
}
