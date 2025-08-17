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
    ll n;
    cin >> n;
    vl r(n), c(n);
    ll r_min = INF, rmax = -INF, cmin = INF, cmax = -INF;
    rep(i, 0, n) {
        cin >> r[i] >> c[i];
        r_min = min(r_min, r[i]);
        rmax = max(rmax, r[i]);
        cmin = min(cmin, c[i]);
        cmax = max(cmax, c[i]);
    }
    cout << max((rmax - r_min + 1)/2, (cmax - cmin + 1)/2 ) << endl;
}


