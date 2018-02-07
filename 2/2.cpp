#include <iostream>
#include <string>
using namespace std;
int main()
{
  int t; cin >> t;
  while( (t--) > 0 ) {
    string s1, s2, reverse; 
    cin >> s1 >> s2;
    s2 = s2 + s2;
    for( int i=s2.size()-1; i>=0; i-- ) {
      reverse.push_back(s2[i]);
    }
    if( s2.find( s1 ) != string::npos || reverse.find( s1 ) != string::npos ) {
      cout << "S" << endl;
    }
    else {
      cout << "N" << endl;
    }
  }
  return 0;
}
