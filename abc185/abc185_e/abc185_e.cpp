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


int main() {
    ll n,m;
    cin >> n >> m;
    vl a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    vvl dp(n+1, vl(m+1, INF));
    dp[0][0] = 0;
    rep(i, 1, n+1) {
        dp[i][0] = i;
    }
    rep(j, 1, m+1) {
        dp[0][j] = j;
    }
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (ll)(a[i-1] != b[j-1])});
        }
    }
    cout << dp[n][m] << endl;
        
}