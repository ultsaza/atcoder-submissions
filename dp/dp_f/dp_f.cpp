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
    string s,t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vvi dp(n+1, vi(m+1,0));
    rep(i,0,n) {
        rep(j,0,m) {
            if (s[i] == t[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
            dp[i+1][j+1] = max({dp[i+1][j+1], dp[i+1][j], dp[i][j+1]});
        }
    }
    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) {
           i--;
        }
        else if (dp[i][j] == dp[i][j-1]) {
            j--;
        }
        else {
            ans = s[i-1] + ans;
            i--;
            j--;
        }
    }
    cout << ans << endl;
}