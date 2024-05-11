#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;


int main() {
   int n,k;
   cin >> n >> k;
   vector<int> a(n);
   rep(i,0,n) cin >> a[i];
   int ans = 0;
   int cur = 0;
   int tmp = 0;
   while(1) {
      if(tmp==n) {ans ++;break;}
      if(cur + a[tmp] <=k) {
         cur += a[tmp];
         tmp++;
      } else {
         cur = 0;
         ans++;
      }
   }
   cout << ans << endl;
}