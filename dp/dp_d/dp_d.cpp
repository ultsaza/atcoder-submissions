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
using mint=modint998244353;
#define INF 1000000009
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

int main() {
    ll n,w;
    cin >> n >> w;
    vvl dp(n+1, vl (w+1,-INF));
    dp[0][0] = 0;
    rep(i,1,n+1) {
        ll w_i,v_i;
        cin >> w_i >> v_i;
        rep(j,0,w+1) {
            if (dp[i-1][j] == -1) continue;
            dp[i][j] = max(dp[i-1][j], (j-w_i>=0 ? dp[i-1][j-w_i] + v_i : -INF));
            
        }
    }
    ll ans = -1;
    rep(i,0,w+1) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}