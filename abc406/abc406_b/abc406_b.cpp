#include <bits/stdc++.h>
#include <atcoder/all>
#include <stdlib.h>
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
    ll n,k;
    cin>>n>>k;
    ll b = 1;
    rep(i,0,k) b *= 10;
    __int128 ans = 1;
    rep(i,0,n) {
        ll a;
        cin >> a;
        if (ans * a < b) ans *= a;
        else ans = 1;
    }
    cout << (ll)ans << endl;
}
