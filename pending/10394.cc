// Problem    : UVa 10394 - Twin Primes
// Time limit : 3.000 seconds
// Difficulty : 2
// Author     : Cody Barnson
// Date       : Jan. 28, 2018
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sz;
bitset<20000010> p;
vector<ll> vp;
vector< pair<int, int> > vtwin;

const ll M = 20000000; // upper bound on values of valid twin prime pairs

// Sieve of Eratosthenes
void sieve(ll m) {
   sz = m + 1;
   p.set();
   p[0] = p[1] = 0;
   for (ll i = 2; i <= sz; i++) {
      if (p[i]) {
	 for (ll j = i * i; j <= sz; j += i) 
	    p[j] = 0;	 
	 vp.push_back(i);
      }
   }
}

// optimized primality check
bool isPrime(ll x) {
   if (x <= sz) 
      return p[x];
   for (int i = 0; i < (int)vp.size(); i++) 
      if (x % vp[i] == 0)
	 return false;   
   return true;
}

int main() {

   sieve(M);

   int size = vp.size();
   for (int i = 0; i < size-1; i++) {
      if (vp[i] + 2 == vp[i+1]) {
	 vtwin.push_back(make_pair(vp[i], vp[i+1]));	 
      }
   }

   int n;
   while (cin >> n) {
      cout << "(" << vtwin[n-1].first << ", " << vtwin[n-1].second << ")" << endl;      
   }
   
   return 0;
}
