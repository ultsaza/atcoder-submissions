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
    ll n, m; cin >> n >> m;
    vector<vector<pl>> G(n);
    rep(i, 0, m) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    ll ans = (1LL << 60);
    vector<bool> visited(n, false);
    auto dfs = [&](auto dfs, ll v, ll min_xor) -> void {
        if (visited[v]) return;
        visited[v] = true;
        for (auto [u, w] : G[v]) {
            if (visited[u]) continue;
            if (u == n-1) {
                ans = min(ans, min_xor ^ w);
                continue;
            }
            dfs(dfs, u, min_xor ^ w);
        }
        visited[v] = false;
    };
    dfs(dfs, 0, 0);
    cout << ans << endl;
}