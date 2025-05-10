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

int main() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i,0,n) cin >> a[i];
    vl s(n);
    s[0] = a[0];
    rep(i,1,n) s[i] = s[i-1] + a[i];
    ll ans = 0;
    rep (i,0,n) {
        ans += a[i] * (s[n-1] - s[i]);
    }
    cout << ans << endl;
}