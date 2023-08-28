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
    int N,h[100009],dp[100009];
    cin >> N;
    rep(i,N) cin >> h[i];
    rep(i,N) dp[i] = INF;
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);
    rep(i,2,N) {
        dp[i] = min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout << dp[N-1];
}