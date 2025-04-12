#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define INF 1e18 // ! lower than 2^60
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;
#define MOD 1000000000

int main() {
   ll n, k;
   cin >> n >> k;
   vl a(n+1);
   vl s(n+1, 0);
   rep(i, 0, k) {
    if (i > n) break;
    a[i] = 1;
    s[i] = i+1;
   }
   rep(i, k, n+1) {
    if (i - k - 1 < 0) {
        a[i] = (s[i - 1]%MOD + MOD)%MOD;
    } else {
        a[i] = (s[i - 1]%MOD - s[i - k - 1]%MOD + MOD)%MOD;
    }
    s[i] = (s[i - 1]%MOD + a[i]%MOD)%MOD;
   }
   cout << a[n] << endl;
   

}