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
using mint=modint1000000007;
#define INF 1000000009
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    vector<vector<mint>> dp(h, vector<mint>(w,0));
    rep(i,0,h) rep(j,0,w) cin >> s[i][j];
    dp[0][0] = 1;
    rep(i,0,h) {
        rep(j,0,w) {
            if (s[i][j] == '#') continue;
            if (i < h-1) dp[i+1][j] += dp[i][j];
            if (j < w-1) dp[i][j+1] += dp[i][j];
        }
    }
    cout << dp[h-1][w-1].val() << endl;

}