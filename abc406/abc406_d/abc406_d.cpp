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
    int h,w,n;
    cin >> h >> w >> n;
    vector<set<int>> x(h), y(w);
    rep(i,0,n) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        x[a].insert(b);
        y[b].insert(a);
    }
    int q;
    cin >> q;
    rep(i,0,q) {
        int t, u;
        cin >> t >> u;
        if (t == 1) {
            u--;
            cout << x[u].size() << endl;
            for(auto v : x[u]) {
                y[v].erase(u);
            }
            x[u].clear();
        } else {
            u--;
            cout << y[u].size() << endl;
            for(auto v : y[u]) {
                x[v].erase(u);
            }
            y[u].clear();
        }
    }
}
