#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i < (int)(n); i++)
const ll M=1000000007;


int main() {
   int n;string s;
   cin >> n >> s;
   bool b=0;
   rep(i,n-2) {
    if(s[i]==s[i+1] && s[i+1]==s[i+2]) b=1;
   }
   if(b) cout << "Yes";
   else cout << "No";
}