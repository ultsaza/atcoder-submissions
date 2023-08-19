#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;

int main() {
    int N,K; cin>>N>>K;
    vector<int> dp(N+1,INF);
    dp[1]=0;
    vector<int> cost(N+1,0);
    rep(i,1,N+1){
        cin>>cost[i];
    }
    rep(i,2,N+1){
        rep(j,1,K+1) {
            if(i-j>0)dp[i]=min(dp[i],dp[i-j]+abs(cost[i]-cost[i-j]));
        }
    }
    cout << dp[N] << '\n';
}

