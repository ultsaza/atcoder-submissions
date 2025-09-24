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
    vl a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    ll s = 0;
    rep(i, 0, n) s += min(a[i],b[i]);
    while(q--) {
        char c;
        cin >> c;
        ll x, v;
        cin >> x >> v;
        x--;
        if (c == 'A') {
            s -= min(a[x], b[x]);
            a[x] = v;
            s += min(a[x], b[x]);
            cout << s << "\n";
        } else {
            s -= min(a[x], b[x]);
            b[x] = v;
            s += min(a[x], b[x]);
            cout << s << "\n";
        }
    }
}