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
	ll n; cin >> n;
	vvl G(n);
	rep(i,0,n-1) {
		ll a,b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ll ans =-1;
	auto dfs=[&](auto dfs, ll v, ll p)->ll {
		ll res = 1; // p->vから始まるalkaneで最大の頂点数
		vl dp;
		for(auto to:G[v]) {
			if(to==p) continue;
			dp.push_back(dfs(dfs, to, v));
		}
		sort(all(dp), greater<ll>());
		if(dp.size()>=3) {
			// pを含む場合でdeg(v)=4
			res = dp[0] + dp[1] + dp[2] + 1;
		}
		if(dp.size()>=4) {
			ans = max(ans, res+dp[3]);
		}
		if(dp.size()>=1) {
			// deg(v)=1 H-Hを除く
			if(dp[0]>1) ans = max(ans, dp[0] + 1);
		}
		return res;
	};

	dfs(dfs, 0, -1);
	cout << ans << endl;
}