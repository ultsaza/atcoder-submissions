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
#define INF 4*10e18
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint=modint998244353;

int main() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i,0,n) cin >> a[i];
    vl dp(n+1, INF);
    dp[0] = 0;
    ll ans = 0;
    rep(i,0,n) {
        ll v = lower_bound(all(dp), a[i]) - dp.begin();
        dp[v] = a[i];
        ans = max(ans, v);
    }
    cout << ans ;

}