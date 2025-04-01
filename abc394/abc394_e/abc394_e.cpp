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
	ll n; cin >>n;
	vector<vector<char>> c(n, vector<char>(n));
	rep(i,0,n)rep(j,0,n) cin >> c[i][j];
	vvl dist(n, vl(n, INF));
	queue<pl> q;
	rep(i,0,n) {
		dist[i][i] = 0;
		q.push({i,i});
	}
	rep(i,0,n)rep(j,0,n) {
		if (i == j) continue;
		if (c[i][j] != '-') {
			dist[i][j] = 1;
			q.push({i,j});
		}
	}
	

	// 小さいdistのやつから伸ばしていく
	// nu->u, v->nv
	while(!q.empty()) {
		auto p = q.front(); q.pop();
		ll u = p.first, v = p.second;
		rep(nu,0,n)rep(nv,0,n) {
			if (c[nu][u] != c[v][nv] || c[nu][u]=='-' || dist[nu][nv] != INF) continue;
			dist[nu][nv] = dist[u][v] + 2;
			q.push({nu,nv});
		}
	}

	rep(i,0,n) {
		rep(j,0,n) {
			if (dist[i][j] == INF) dist[i][j] = -1;
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}