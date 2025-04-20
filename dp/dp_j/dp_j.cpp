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
   vector<vector<vector<ld>>> dp(302, vector<vector<ld>>(302, vector<ld>(302, 0)));
   vector<int> a(3,0);
   rep(i,0,n) {
    int b;
    cin >> b;
    b--;
    a[b]++;
   }

   rep(k,0,n+1) rep(j,0,n+1) rep(i,0,n+1) {
    int s = i+j+k;
    if (s == 0) continue;
    dp[i][j][k] = (double) n;
    if (i > 0) dp[i][j][k] += dp[i-1][j][k] * i;
    if (j > 0) dp[i][j][k] += dp[i+1][j-1][k] * j;
    if (k > 0) dp[i][j][k] += dp[i][j+1][k-1] * k;
    dp[i][j][k] /= (double) s;
   }

   cout << fixed << setprecision(15) << dp[a[0]][a[1]][a[2]] << endl;


   
}