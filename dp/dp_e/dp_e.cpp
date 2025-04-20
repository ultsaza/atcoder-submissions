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
    vvl dp(n+1, vl(100001, INF));
    dp[0][0] = 0;
    rep(i,1,n+1) {
        ll w_i,v_i;
        cin >> w_i >> v_i;
        rep(j,0,100001) {
           dp[i][j] = min(dp[i-1][j], (j-v_i>=0 ? dp[i-1][j-v_i] + w_i : INF));
        }
    }
    ll ans = 0;
    rep(i,0,100001) {
        if (dp[n][i] <= w) ans = max(ans, i);
    }
    cout << ans << endl;
}