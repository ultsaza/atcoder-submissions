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


// 辺の定義
struct Edge {
    long long u;
    long long v;
    long long cost;
};
bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; } // 辺を直接比較するための関数
/* Kruskal :クラスカル法で minimum spanning tree を求める構造体
    入力: 辺のvector, 頂点数V
    最小全域木の重みの総和: sum
    計算量: O(|E|log|V|)
*/
struct Kruskal {
    dsu uft;
    long long sum;  // 最小全域木の重みの総和
    vector<Edge> edges;
    vector<Edge> used_edges;
    int V;
    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }
    void init() {
        sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
        uft = dsu(V);
        sum = 0;
        for (auto &e : edges) { // 参照で受け取るように修正
            if (!uft.same(e.u, e.v)) { // 閉路にならなければ加える
                uft.merge(e.u, e.v);
                sum += e.cost;
                used_edges.push_back(e);
            }
        }
    }
};
int main() {
    ll n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    ll total_cost = 0;
    rep(i, 0, m) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        edges[i] = {u, v, c};
        total_cost += c;
    }
    Kruskal kruskal(edges, n);
    ll ans = total_cost - kruskal.sum;
    
    // Add operator< to Edge struct to allow comparison
    struct EdgeCompare {
        bool operator()(const Edge& a, const Edge& b) const {
            if (a.u != b.u) return a.u < b.u;
            if (a.v != b.v) return a.v < b.v;
            return a.cost < b.cost;
        }
    };
    
    set<Edge, EdgeCompare> used_edges;
    for (size_t i = 0; i < kruskal.used_edges.size(); i++) {
        used_edges.insert(kruskal.used_edges[i]);
    }
    for (auto &e : edges) {
        if (used_edges.count(e)) continue;
        if (e.cost < 0) {
            ans -= e.cost;
        }
    }
    cout << ans << endl;
}