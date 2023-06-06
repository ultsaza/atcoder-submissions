#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main() {
   string n;
   cin >> n;
   int m=n.size();
   for(int i=3;i<m;i++) {
    n[i]='0';
   }
   cout << n;
}