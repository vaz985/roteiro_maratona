#include <bits/stdc++.h>
using namespace std;
struct aluno
{
  string name;
  int pts;
};
bool comp( struct aluno a, struct aluno b ) 
{
  if( a.pts > b.pts )
    return true;
  else if( a.pts == b.pts && a.name.compare(b.name) ) {
    return true;
  }
  else
    return false;
};
int main()
{
  list<struct aluno> l;
  int n;
  int instancia = 1;
  while( 1 ) {
    cin >> n;
    if( cin.eof() )
      exit(0);
    for( int i=0; i<n; i++ ) {
      struct aluno x;
      cin >> x.name >> x.pts;
      l.push_back(x);
    }
    l.sort(comp);
    cout << "Instancia " << instancia++ << endl;
    cout << l.back().name << endl << endl;
    l.clear();
  } 
  return 0;
}
