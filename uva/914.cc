// Problem : UVa 914 - Jumping Champion
// Author  : Cody Barnson
// Date    : Dec. 30, 2017
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
      if (x % v[i] == 0) {
	 return false;
      }      
   }
   return true;
}

int main() {

   // preprocessing; compute primes up to 1,000,000 and store in vector
   ll MM = 1000000;
   ll m = sqrt(MM);
   sieve(m);

   // compute the larger primes using optimized primality testing, then append
   // to our vector of primes.
   vector<int> large;
   for (ll i = size + 1; i <= MM; i++) {
      if (isPrime(i)) {
	 large.push_back((int)i);
      }
   }
   v.insert(end(v), begin(large), end(large));

   // compute the adjacent difference between consecutive primes
   vector<int> diff;
   diff.reserve(v.size());
   adjacent_difference(begin(v), end(v), begin(diff));

   // read number of test cases
   int t;
   cin >> t;

   // process 't' cases
   while (t--) {
      int lo, hi;
      cin >> lo >> hi;
      
      // find left and right indices in our vector of primes, where the left is
      // the index of the first prime number which is not less than lo, and
      // right is the index of the first prime number > hi
      auto left = lower_bound(v.begin(), v.end(), lo);
      auto right = upper_bound(v.begin(), v.end(), hi);

      // maintain a count of each frequency in the vector<int> diff within the
      // range identified; hold max at any given point
      map<int, int> vc;
      // pair<int, int> best = make_pair(-1, -1);
      int l = left - begin(v), r = right - begin(v);

      
      bool tie = false;
      int high = -1, ans = -1;

      // There must be at least 2 PRIMES contained in the specified range,
      // otherwise we have nothing to count.  
      if (r - l > 1) {
	 for (int i = l + 1; i < r; i++) {
	    if (i == 0) continue;
	    vc[diff[i]] += 1;
	    if (high < vc[diff[i]]) {
	       high = vc[diff[i]];
	       ans = diff[i];
	       tie = false;
	    } else if (high == vc[diff[i]]) {
	       tie = true;
	    }
	 }
      } else {
	 tie = true;
      }

      if (tie) {
	 cout << "No jumping champion" << endl;
      } else {
	 cout << "The jumping champion is " << ans << endl;
      }

      

      // cout << "best is number " << best.first << ", with " << best.second << " occurrences" << endl;
      
   }



   return 0;
}
