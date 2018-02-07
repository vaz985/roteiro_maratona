#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n; cin >> n;
  while( (n--) > 0 ) {
    bool ordered = true;
    string s2; cin >> s2;
    string s = s2;
    for( int i=0; i<(s.size()-1); i++ ) {
      if( s[i] > 0x5A )
        s[i] -= 0x20;
      if( s[i+1] > 0x5A )
        s[i+1] -= 0x20;
      if( s[i] >= s[i+1] ) {
        ordered = false; 
      }
    }
    if( ordered == true ) {
      cout << s2 << ": O" << endl;
    }
    else
    if ( ordered == false ) {
      cout << s2 << ": N" << endl;
    }
  }
  return 0;
}
