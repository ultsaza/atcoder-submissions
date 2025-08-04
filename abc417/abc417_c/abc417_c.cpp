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
    vl a(n);
    rep(i, 0, n) cin >> a[i];
    map<ll, ll> mp;
    ll ans = 0;
    rep(i, 0, n-1) {
        mp[a[i] + i + 1]++;
        if (mp.count(i+2-a[i+1])) {
            ans += mp[i+2-a[i+1]];
        }
    }
    cout << ans << endl;
}

