#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 1; i <=(int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i <= (int)(n); i++)
const ll M=1000000007;


int main() {
    // cout << max(dp[n][1],dp[n][0])
    int n; cin >> n;
    vector<ll> x(n+1);
    vector<ll> y(n+1);
    rep(i,n) cin >> x[i] >> y[i];
    vector<vector<ll>> dp(n+1,vector<ll> (2));
    rep2(i,0,n) {
        dp[i][0]=-M;
        dp[i][1]=-M;
    }
    dp[0][0]=0;
    rep(i,n) {
        if(x[i]==0) dp[i][0]=max(dp[i-1][0],max(dp[i-1][0],dp[i-1][1])+y[i]);
        if(x[i]==1) dp[i][1]=max(dp[i-1][0]+y[i],dp[i-1][1]);
        dp[i][0]=max(dp[i][0],dp[i-1][0]);
        dp[i][1]=max(dp[i][1],dp[i-1][1]);
    }
    cout << max(dp[n][1],dp[n][0]);
}