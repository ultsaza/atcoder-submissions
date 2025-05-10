#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using ld = long double;
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint1000000007;
const ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vvi G(n);
    rep(i,0,n-1) {
        ll a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<mint> dp_black(n), dp_white(n);
    auto dfs = [&](auto dfs, ll v, ll p) -> pair<mint,mint> {
        dp_black[v] = 1, dp_white[v] = 1;
        for (auto u: G[v]) {
            if (u == p) continue;
            auto [black_u, white_u] = dfs(dfs, u, v);
            dp_black[v] *= white_u;
            dp_white[v] *= black_u + white_u;
        }
        return {dp_black[v], dp_white[v]};
    };
    dfs(dfs, 0, -1);
    cout << (dp_black[0] + dp_white[0]).val() << endl;
}