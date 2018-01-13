// Problem    : UVa 543 - Goldbach's Conjecture
// Time limit : 3.000 seconds
// Difficulty : 1
// Author     : Cody Barnson
// Date       : Dec. 31, 2017
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll size;
vector<int> v; 
bitset<10000010> primes; // 10000010 works for most cases, tweak if necessary

// Sieve of Eratosthenes
void sieve(ll m) {
   size = m + 1;
   primes.set();
   primes[0] = primes[1] = 0;
   for (ll i = 2; i <= size; i++) {
      if (primes[i]) {
	 for (ll j = i * i; j <= size; j += i) {
	    primes[j] = 0;
	 }
	 v.push_back((int)i);
      }
   }
}

// Optimized primality test
bool isPrime(ll x) {
   if (x <= size) {
      return primes[x];
   }
   for (int i = 0; i < (int)v.size(); i++) {
      if (x % v[i] == 0)
	 return false;
   }
   return true;
}

int main() {

   // preprocessing step
   ll MM = 1000000;
   ll m = sqrt(MM);
   sieve(m);

   // process each test case
   int n;
   while (cin >> n && n != 0) {

      // Since, n = i + (n - i), we only need to check primality for the
      // 'outermost' elements being consider (which inherently add up to the
      // desired sum.  The first incidence of a match is the greatest
      // difference, as desired.  If no match, i will equal n upon exiting
      // the for-loop
      int i;
      for (i = 0; i < n; i++) {
	 if (isPrime(i) && isPrime(n - i)) {
	    cout << n << " = " << i << " + " << n - i << endl;
	    break;
	 }
      }

      if (i == n) {
	 cout << "Goldbach's conjecture is wrong." << endl;
      }
   }

   return 0;
}
