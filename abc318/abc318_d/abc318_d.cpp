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
#define INF 1e18
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;


int main() {
    ll n;
    cin >> n;
    vvl d(n, vl(n, 0));
    rep(i,0,n) {
		for(ll j = i + 1; j < n; j++) cin >> d[i][j];
	}
    vl dp(1<<n, 0LL);
    // b: その頂点を含むかどうかが確定したことを表す系列.
    rep(b,0,(1<<n) - 1) {
        ll l = -1;
        // bに含まれない最小番号の頂点に注目する.
        // 完全グラフなので一つの頂点からの遷移のみ調べれば良い.
        rep(i,0,n) if(!((b>>i) & 1)) {
            l = i;
            break;
        }

        rep(i,0,n) if(!((b>>i) & 1)){
            ll nb = b | (1 << l) | (1 << i);
            dp[nb] = max(dp[nb], dp[b] + d[l][i]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;


}