#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;

int main() {
	ll n;
	cin >> n;
	map<ll, vector<ll>> mp;
	rep(i, 0, n) {
		ll a;
		cin >> a;
		mp[a].push_back(i+1);
	}
	ll ans = -1;
	ll max_k = -1;
	for (auto& [k, v]: mp) {
		if (v.size() == 1) {
			if (k > max_k) {
				max_k = k;
				ans = v[0];
			}
		}
	}
	cout << ans << endl;
}