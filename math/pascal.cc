#include <bits/stdc++.h>
using namespace std;
void PascalsTriangle(int);

int main() 
{   
   int n;
   cout << "Enter the number of rows you would like to print for Pascal's Triangle: "; 
   cin >> n;
   PascalsTriangle(n);
   return 0; 
}

void PascalsTriangle (int n){
   int i,j,x;  
   for(i=0;i<n;i++) 
   { 
      x=1;
      cout << i << ": ";
      for(j=0;j<=i;j++) 
      { 
	 cout << x << " "; 
	 x = x * (i - j) / (j + 1); 
      } 
      cout << endl; 
   } 
}
