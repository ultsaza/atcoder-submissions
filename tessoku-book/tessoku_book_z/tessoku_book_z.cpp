#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
 bool isPrime(int x) {
      for(int i=2;i*i<=x;i++) {
         if(x%i==0) return false;
      }
      return true;
   }
int main() {
   int q,x[10009];
   cin >> q;
   for(int i=1;i<=q;i++) {
      cin >> x[i];
   }
   for(int i=1;i<=q;i++) {
      bool ans = isPrime(x[i]);
      if(ans) {
         cout << "Yes";
      } else {
         cout << "No";
      }
      cout << endl;
   }
}