#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint=modint998244353;

int main() {
    ll n, m;
    cin >> n >> m;
    vl a(n);
    ll k = 0;
    rep(i,0,n) {
        cin >> a[i];
        k += a[i];
    }
    rep(i,0,n) {
        if (k - a[i] == m) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
