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
    ll n;
    cin >> n;
    ll ans = 0;
    vvl a(n+1);
    rep(i,1,n+1) a[i].push_back(0);
    rep(i,0,n) {
        ll x;
        cin >> x;
        a[x].push_back(i+1);
    }
    rep(i,1,n+1) a[i].push_back(n+1);
    rep(i,1,n+1) {
        if (a[i].size() == 2) continue;
        ll tmp = 0;
        rep(j,0,a[i].size()-1) {
            ll d = a[i][j+1] - a[i][j];
            tmp += d*(d-1)/2;
        }
        ans += (n+1)*n/2 - tmp;
    }
    cout << ans << endl;
}