// Combinations
// Author : Cody Barnson
// Date   : Dec. 19, 2017
#include <bits/stdc++.h>
using namespace std;

// C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
// for all integers n,k : 1 <= k <= n - 1
int C(int n, int k) {
   if (n < 0 || k < 0 || k > n)
      return 0;
   
   // base cases
   if (k == 0 || k == n)
      return 1; // for all integers n >= 0

   return C(n - 1, k - 1) + C(n - 1, k);
}

int main() {

   

   
   int n, k;
   cout << "Enter values to produce 'n choose k': ";
   while (cin >> n >> k) {
      cout << n << " choose " << k << ": " << C(n, k) << endl;
   }
   
   return 0;
}
