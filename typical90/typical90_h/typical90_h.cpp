#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, r) for (ll i = 0; i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll M = 1000000007;

int main() {
   int N;
   string S;
   string T = "atcoder";
   cin >> N >> S;
   unsigned int dp[N + 1][T.size() + 1];

   
   rep(i, N + 1) {
    rep(j, T.size() + 1) {
        dp[i][j] = 0;
    }
   }
   dp[0][0] = 1;

   rep(i, N) {
    rep(j, T.size() + 1) {
        dp[i + 1][j] = (dp[i + 1][j]% M + dp[i][j]% M) % M;

        if(S[i] == T[j] && j < T.size()) {
            dp[i + 1][j + 1] = (dp[i + 1][j + 1]% M + dp[i][j]% M) % M;

        }
    }
   }

   cout << dp[N][T.size()];
}
