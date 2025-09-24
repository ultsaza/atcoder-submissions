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
    ll n, q;
    cin >> n >> q;
    dsu uf(n);
    vector<bool> flag(n, false);
    vector<ll> s(n, 0);
    while(q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll u, v;
            cin >> u >> v;
            u--; v--;
            if ( uf.same(u, v) ) continue;
            ll ns = s[uf.leader(u)] + s[uf.leader(v)];
            uf.merge(u, v);
            s[uf.leader(u)] = ns;
        }
        else if (t == 2) {
            ll v;
            cin >> v;
            v--;
            s[uf.leader(v)] += flag[v]? -1:1;
            flag[v] = !flag[v];
        }
        else {
            ll v;
            cin >> v;
            v--;
            if (s[uf.leader(v)] > 0) {
                cout << "Yes" << "\n";
            }
            else {
                cout << "No" << "\n";
            }
        }
    }
}