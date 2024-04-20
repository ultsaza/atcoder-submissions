#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;

long double dp(ll n, ll a,ll x, ll y, map<ll, long double> &mp) {
    // mp[N] : expectation of N

    // alraedy calculated
    if (mp.find(n) != mp.end()) return mp[n];


    long double op1 = dp(n/a, a, x, y, mp) + x;
    long double op2 = y * 6.0 / 5.0;
    for(ll i=2;i<=6;i++) {
        op2 += dp(n/i,a,x,y,mp)/(long double)5.0;
    }
    mp[n] = min(op1,op2);

    return min(op1,op2);

}

int main() {
    ll n, a, x, y;
    cin >> n >> a >> x >> y;
    map<ll, long double> mp;
    mp[0] = 0;
    cout << fixed << setprecision(20) << dp(n, a, x, y, mp) << endl;
    return 0;
}