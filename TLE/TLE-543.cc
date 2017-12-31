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
bitset<10000010> primes;

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

void computePrimes() {
   ll MM = 1000000;
   ll m = sqrt(MM);
   sieve(m);
   vector<int> big;
   for (ll i = size + 1; i <= MM; i++) {
      if (isPrime(i))
	 big.push_back((int)i);
   }
   v.insert(end(v), begin(big), end(big));   
}

int main() {

   // preprocessing step.  Here we find all primes up to 1000000
   computePrimes();
   int n;
   while (cin >> n && n != 0) {

      set< tuple<int, int, int> > st;

      // find iterator to first prime that is not less than n
      auto end = lower_bound(v.begin(), v.end(), n);

      for (auto i = v.begin(); i != end; ++i) {
	 for (auto j = v.begin(); j != end; ++j) {
	    if (*i + *j == n) {
	       st.insert(make_tuple(abs(*i - *j), *i, *j));
	    }
	 }
      }

      if (st.empty()) {
	 cout << "Goldbach's conjecture is wrong." << endl;
      } else {
	 auto ans = st.crbegin();
	 int a = get<1>(*ans), b = get<2>(*ans);
	 cout << n << " = " << min(a, b) << " + " << max(a, b) << endl;
      }
	 
      
   }
   

   return 0;
}
