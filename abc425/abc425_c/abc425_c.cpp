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
#define INF 4*10e18
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint = modint1000000007;

int main() {
    ll n, q;
    cin >> n >> q;
    vl a(2*n);
    rep(i,0,n) {
        ll x;
        cin >> x;
        a[i] = x;
        a[n+i] = x;
    }
    vl s(2*n+1,0);
    rep(i,0,2*n) {
        s[i+1] = s[i] + a[i];
    }
    ll sh = 0;
    while(q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll c;
            cin >> c;
            sh += c;
            sh %= n;
        } else {
            ll l, r;
            cin >> l >> r;
            cout << s[r + sh] - s[l + sh - 1] << endl;
        }
    }
}
  