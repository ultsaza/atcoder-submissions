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
using mint=modint1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    scc_graph g(n);
    rep(i,0,m) {
        ll a,b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a, b);
    }
    ll ans = 0;
    vector<vector<int>> f = g.scc();
    rep(i,0,f.size()) {
        ans += (f[i].size()*(f[i].size()-1))/2;
    }
    cout << ans;
}