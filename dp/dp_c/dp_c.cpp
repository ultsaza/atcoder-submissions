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
#define INF 1000000009
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

int main() {
    ll n;
    cin >> n;
    vvl dp(n, vector<ll> (3));
    int a,b,c;
    cin >> a >> b >> c;
    dp[0][0] = a;
    dp[0][1] = b;
    dp[0][2] = c;
    rep(i,1,n) {
        int x,y,z;
        cin >> x >> y >> z;
        dp[i][0] = max(dp[i-1][1]+x, dp[i-1][2]+x);
        dp[i][1] = max(dp[i-1][0]+y, dp[i-1][2]+y);
        dp[i][2] = max(dp[i-1][0]+z, dp[i-1][1]+z);
    }
    ll ans = 0;
    rep(i,0,3) ans = max(ans, dp[n-1][i]);
    cout << ans << endl;

}