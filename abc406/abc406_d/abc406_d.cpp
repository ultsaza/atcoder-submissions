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
    ll h,w,n;
    cin >> h >> w >> n;
    map<ll, set<ll>> gx, gy;
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        gx[x].insert(y);
        gy[y].insert(x);
    }
    ll q;
    cin >> q;
    while(q--) {
        ll t, c;
        cin >> t >> c;
        switch (t) {
            case 1: {
                cout << gx[c].size() << "\n";
                for (auto y: gx[c]) {
                    gy[y].erase(c);
                }
                gx[c].clear();
            }
            break;
            case 2: {
                cout << gy[c].size() << "\n";
                for (auto x: gy[c]) {
                    gx[x].erase(c);
                }
                gy[c].clear();
            }
            break;
        }
    }
}
