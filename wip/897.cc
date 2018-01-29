// Problem    : UVa 897 - Anagrammatic Primes
// Time limit : 3.000 seconds
// Difficulty : 3
// Author     : Cody Barnson
// Date       : Jan. 14, 2018
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll size;
bitset<10000010> bs;
vector<ll> p;

void sieve(ll m) {
   size = m + 1;
   bs.set();
   bs[0] = bs[1] = 0;
   for (ll i = 2; i <= size; i++) {
      if (bs[i]) {
	 for (ll j = i * i; j <= size; j += i) {
	    bs[j] = 0;
	 }
	 p.push_back(i);
      }
   }
}

bool isPrime(ll x) {
   if (x <= size)
      return bs[x];
   for (int i = 0; i < (int)p.size(); i++) {
      if (x % p[i] == 0)
	 return false;
   }
   return true;
}

const string evens = "02468";

bool isAna(ll x) {

   if (x == 2)
      return true;
   string s = to_string(x);
   sort(s.begin(), s.end());
   size_t f = s.find_first_of(evens);
   if (f == string::npos) {
      do {
	 ll y = stoll(s);
	 if (!isPrime(y))
	    return false;
      } while (next_permutation(s.begin(), s.end()));
      return true;
   }
   return false;
}

int main() {


   
   ll m = sqrt(10000000);
   sieve(m);

   int n;
   while (cin >> n && n != 0) {

      string s = to_string(n);
      int power = s.length();
      ll hi = pow(10, power);
      
      ll i;
      for (i = n + 1; i < hi; i++) {
	 if (isAna(i)) {
	    cout << i << endl;
	    break;
	 }
      }
      if (i == hi)
	 cout << 0 << endl;
      
   }


   return 0;
}
