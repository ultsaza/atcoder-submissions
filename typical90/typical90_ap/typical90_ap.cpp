#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using ld = long double;
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint1000000007;
const ll INF = 1e18;

int main() {
    ll K;
    cin >> K;
    vector<mint> dp(100009);
    dp[1] = 1;
    rep(i,2,10) {
        rep(j,1,i) {
            dp[i] += dp[i-j];
        }
        dp[i] += 1;
    }
    rep(k,10,K+1) {
        rep(i,1,10) {
            dp[k] += dp[k-i];
        }
    }
    if (K%9 == 0)cout << dp[K].val() << endl;
    else cout << 0 << endl;

}