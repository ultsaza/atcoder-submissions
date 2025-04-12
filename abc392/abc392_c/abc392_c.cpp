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
using mint=modint998244353;
#define INF 1e18 
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


int main() {
    ll n; cin >> n;
    vl p(n+1), q(n+1);
    rep(i,1,n+1) cin >> p[i];
    rep(i,1,n+1) cin >> q[i];
    map<ll,ll> mp;
    rep(i,1,n+1) mp[q[i]] = q[p[i]];
    rep (i,1,n+1) {
        cout << mp[i] << " ";
    }
     
}