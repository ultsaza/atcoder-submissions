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
    ll n,m;
    cin>>n>>m;
    vvl G(n);   
    vl a(m);
    rep(i,0,m){
        int x;
        cin>>x;
        a[i] = x-1;
    }
    vl b(m);
    rep(i,0,m){
        int x;
        cin>>x;
        b[i] = x-1;
    }
    rep(i,0,m){
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);

    }
    // Gが二部グラフかを判定

    vector<bool> visited(n, false);
    vector<int> color(n, 0);
    bool bipartite = true;
    
    auto dfs = [&](auto dfs, int v) -> void{
        visited[v] = true;
        for (int u : G[v]) {
            if (!visited[u]) {
                color[u] = 1 - color[v];
                dfs(dfs, u);
            } else if (color[u] == color[v]) {
                bipartite = false;
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(dfs, i);
        }
    }

    cout << (bipartite ? "Yes" : "No") << endl;
}