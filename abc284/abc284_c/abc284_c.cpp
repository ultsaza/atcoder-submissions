#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const int INF = 0x3fffffff;
const ll LINF = 0x1ffffffffffffff;


int N,M;
vector<vector<int>> G;
vector<bool> visited;
int ans = 0;

void dfs(int v) {
    visited[v] = 1;
    for(auto nv:G[v]) {
        if(visited[nv]) continue;
        dfs(nv);
    }
}

int main() {
    cin >> N >> M;
    G.resize(N);
    visited.resize(N,0);
    rep(i,M) {
        int v,u;
        cin >> v >> u;
        G[v-1].push_back(u-1);
        G[u-1].push_back(v-1);
    }
    rep(i,N) {
        if(visited[i]) continue;
        dfs(i);
        ans++;
    }
    cout << ans << endl;
}