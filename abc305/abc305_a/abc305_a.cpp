#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const ll M=1000000007;

int main() {
   int n,d[21],ans=0;
   cin >> n;
   rep(i,21) {
    d[i]=abs(i*5 - n);
   }
   rep(i,21) {
    if(d[ans]>=d[i]) {
        ans = i;
    }
   }
   cout << (ans)*5;
}