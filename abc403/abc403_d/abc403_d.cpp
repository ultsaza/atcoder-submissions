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
using mint=modint998244353;

int main() {
    ll n,d;
    cin >> n >> d;
    if (d == 0) {
        set<int> s;
        rep(i,0,n) {
            int a; cin >> a;
            s.insert(a);
        }
        cout << n - s.size() << endl;
    } else {
        vector<ll> t(1000001, 0);
        rep(i,0,n) {
            ll a;
            cin >> a;
            t[a]++;
        }
        ll ans = 0;
        rep(i,0,d) {
            vl dp((1000000-i)/d + 2,0);
            rep(j,1,(1000000 - i)/d + 1) {
                dp[j+1] = min(dp[j] + t[(j)*d + i],dp[j-1]+t[(j-1)*d + i]);
            }
            ans += dp[(1000000 - i)/d + 1];
        }
        cout << ans << endl;
    }

}