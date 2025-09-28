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
    ll n;
    cin >> n;
    ll ans = 0;
    ll sign = -1;
    rep(i,1,n+1) {
        ans += i*i*i * sign;
        sign *= -1;
    }
    cout << ans << endl;
}