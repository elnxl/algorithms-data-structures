#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

void solve(string s)
{
  int n = s.size(), i, j;
 
   const int p = 91;
   const long long maxmod = 1000000007;
   vector<long long> hash( n );
   vector<long long> hash_rev( n ); 
   vector<long long> pows( n );
 
   hash[ 0 ] = int( s[ 0 ] );
   pows[ 0 ] = 1;
   for( i = 1; i < n; ++i )
   {
      hash[ i ] = hash[ i - 1 ] * p + int( s[ i ] );
      hash[ i ] %= maxmod;
      pows[ i ] = pows[ i - 1 ] * p % maxmod;
   }
 
   hash_rev[ n - 1 ] = int( s[ n - 1 ] );
   for( i = n - 2; i >= 0; --i )
   {
      hash_rev[ i ] = hash_rev[ i + 1 ] * p + int( s[ i ] );
      hash_rev[ i ] %= maxmod;
   }
 
   for( i = 1; i < n; ++i )
   {
      long long hleft = hash[ n - 1 ];
      hleft -= hash[ i - 1 ] * pows[ n - i ] % maxmod;
      if( hleft < 0 )
         hleft += maxmod;
 
      long long hright = hash_rev[ i ];
 
      if( hleft == hright )
      {
         cout << s;
         string t = s.substr( 0, i );
         reverse( t.begin(), t.end() );
         cout << t << endl;
         return;
      }
   }
   cout << s << s << endl;
}
 
int main()
{
  string s;
   cin >> s;
   solve(s);
   return 0;
}