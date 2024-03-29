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

void dfs(int v) {
    visited[v] = 1;
    for(auto nv: G[v]) {
        if(visited[nv]) continue;
        dfs(nv);
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    G.resize(N);
    visited.resize(N);
    vector<int> deg(N);
    rep(i,M) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        deg[u]++;
        deg[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0);

    bool flag = true;
    rep(i,N) {
        flag &= visited[i];
        if(deg[i]>2) flag = false;
    }
    if(!flag || (N-1!=M)) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';


}