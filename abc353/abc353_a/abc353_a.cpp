#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;


int main() {
   int n;
   cin >> n;
   vector<int> h(n);
   rep(i, 0, n) cin >> h[i];
   rep(i,1,n) {
      if(h[0]<h[i]) {
         cout << i+1 << '\n';
         return 0;
      }
   }
   cout << -1 << '\n';
   return 0;
}