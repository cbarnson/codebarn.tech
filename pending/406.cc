// Problem    : UVa 406 - Prime Cuts
// Time limit : 3.000 seconds
// Difficulty : 2
// Author     : Cody Barnson
// Date       : Jan. 13, 2018
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sz;
bitset<10000010> bs;
vector<int> p;

void sieve(ll n) {
   sz = n + 1;
   bs.set();
   bs[0] = bs[1] = 0;
   for (ll i = 2; i <= sz; i++) {
      if (bs[i]) {
	 for (ll j = i * i; j <= sz; j += i) 
	    bs[j] = 0;	 
	 p.push_back(i);
      }
   }
}

int main() {

   // include 1 in the list of primes
   p.push_back(1);

   // compute primes up to 1000, store in p
   ll m = 1000;
   sieve(m);

   int n, c;
   while (cin >> n >> c) {

      cout << n << " " << c << ":";

      // std::upper_bound returns iterator to first element in range
      // [p.begin(), p.end()) which compares greater than n
      auto end = upper_bound(p.begin(), p.end(), n);
      int i = end - p.begin();

      int num = (i & 1) ? 2*c-1 : 2*c;
      int skip = max(i-num, 0) / 2;
      
      for (int j = skip; j < (i - skip); j++) {
	 cout << " " << p[j];
      }
      cout << endl << endl;
   }

   return 0;
}
