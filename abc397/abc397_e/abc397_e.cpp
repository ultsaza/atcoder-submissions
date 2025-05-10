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

int main() {
    int n,k;
    cin >> n >> k;
    int nk = n*k;
    vvi G(nk);
    rep(i,0,nk-1){
        int u,v; cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bool ok = true;
    auto dfs = [&](auto dfs, int v, int p = -1) -> int {
        int res = 1;
        int deg = 0;
        for(auto nv:G[v]){
            if (nv == p) continue;
            int sz = dfs(dfs,nv,v);
            // kの倍数ごとにグループ化して次数のカウント.
            if (sz%k) deg++;
            res += sz;
        }
        if (res%k) deg++;
        if (deg > 2) ok = false;
        return res;
    };
    dfs(dfs,0);
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}