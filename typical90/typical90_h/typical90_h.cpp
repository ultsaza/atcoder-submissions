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
using mint=modint1000000007;

int main() {
     ll n; 
     cin >> n;
     string s;
     cin >> s;
     vector<vector<mint>> dp(n+1, vector<mint> (8,0));
     string t = "atcoder";
     dp[0][0]++;
     rep(i,0,n) {
        rep(j,0,t.size()+1) {
            if (s[i]==t[j]&&j!=t.size()) {
                dp[i+1][j+1] += dp[i][j];
            }
            dp[i+1][j] += dp[i][j];
        }
     }
     cout << dp[n][7].val() << endl;
} 