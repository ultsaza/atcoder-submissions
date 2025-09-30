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
const ll INF = 1e18;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint = modint1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    dsu uf(n);
    rep(i,0,m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        uf.merge(a,b);
    }
    ll ans = 0;
    for(auto v: uf.groups()) {
        ans += ((v.size()) * (v.size() - 1)) /2;
    }
    ans -= m;
    cout << ans;

}