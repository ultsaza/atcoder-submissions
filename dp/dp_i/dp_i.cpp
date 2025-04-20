#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using mint=modint1000000007;
#define INF 1e18
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

int main() {
    int n;
    cin >> n;
    vector<ld> p(n);
    rep(i,0,n) cin >> p[i];
    vector<ld> dp(n+1, 0);
    // j枚表の確率 loopごとに更新させる
    dp[0] = 1.0;
    rep(i,0,n) {
        vector<ld> old(n+1);
        swap(dp, old);
        rep(j,0,n+1) {
            dp[j] += old[j] * (1-p[i]);
        }
        rep(j,0,n) {
            dp[j+1] += old[j] * p[i];
        }
    }
    ld ans = 0;
    for(int i=(n+1)/2; i<=n; i++) ans += dp[i];
    cout << fixed << setprecision(15) << ans << endl;

}