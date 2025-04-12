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
#define INF 1e18 
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

struct Edge {
    ll u;
    ll v;
    ll cost;
};
int main() {
    ll n,m; cin >> n >> m;
    vector<Edge> edges(m);
    rep(i,0,m) {
        ll u,v,c; cin >> u >> v >> c;
        u--; v--;
        edges[i] = {u,v,c};
    }
    sort(all(edges), [&](const Edge &a, const Edge &b) {
        return a.cost < b.cost;
    });
    dsu d(n);
    ll total_cost = 0;
    ll min_cost = 0;
    for (auto e : edges) {
        total_cost += e.cost;
        if (d.same(e.u, e.v)) {
            if (e.cost < 0) min_cost += e.cost;
            continue;
        }
        d.merge(e.u, e.v);
        min_cost += e.cost;
    }
    cout << total_cost - min_cost << endl;
    
}