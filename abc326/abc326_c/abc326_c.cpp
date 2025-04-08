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
#define INF 1e18
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;


int main() {
    ll n,m; cin >> n >> m;
    vl a(n);
    rep(i,0,n) cin >> a[i];
    sort(all(a));
    ll l = 0, r =0;
    ll ans = 0;

    while(r < n) {
        if (a[r] - a[l] < m) {
            r++;
            ans = max(ans, r - l);
        } else
            l++;
    }

    cout << ans << endl;
}