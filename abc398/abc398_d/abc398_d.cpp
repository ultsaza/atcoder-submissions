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
	ll n, r, c;
	cin >> n >> r >> c;
	string s;
	cin >> s;

	
	set<pair<ll, ll>> grid;


	// 最初player は(2N, 2N)にいる
	// 煙が生成されるのは最初(2N-R, 2N-C)から

	pair<ll, ll> player = {2*n, 2*n};
	pair<ll, ll> smoke = {2*n-r, 2*n-c};

	grid.insert(smoke);
	rep(i, 0, n) {

		if (s[i]=='N') {
			player.first += 1;
			smoke.first += 1;
		}
		if (s[i]=='S') {
			player.first -= 1;
			smoke.first -= 1;
		}
		if (s[i]=='E') {
			player.second -= 1;
			smoke.second -= 1;
		}
		if (s[i]=='W') {
			player.second += 1;
			smoke.second += 1;
		}

		grid.insert(smoke);

		//cout <<"test: player"<< player.first -2*n << " " << player.second-2*n << endl;
		//cout <<"test: smoke"<< smoke.first-2*n << " " << smoke.second -2*n<< endl;
		if(grid.count(player)) {
			cout << 1;
		} else {
			cout << 0;
		}
	}


}