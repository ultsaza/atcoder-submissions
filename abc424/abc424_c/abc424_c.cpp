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
#define INF 10e18
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint=modint998244353;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(i+1);
        g[b].push_back(i+1);
    }
    vector<bool> seen(n + 1, false);
    auto dfs = [&](auto self, ll v) -> void {
        seen[v] = true;
        for(auto nv: g[v]) {
            if (!seen[nv]) self(self, nv);
        }
    };
    dfs(dfs, 0);
    ll ans = 0;
    rep(i, 0, n + 1) {
        ans += seen[i];
    }
    cout << ans - 1 << endl;
}