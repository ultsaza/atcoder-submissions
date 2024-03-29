#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const int INF = 0x3fffffff;
const ll LINF = 0x1ffffffffffffff;


vector<vector<int>> dp[10][10]; //S_{N,M}のリスト

//方針: dp[n][m]はdp[n-1][k-1]の成分にkを追加することで構成できる
//再帰による実装を行う

void solve(int n,int m) {
    //再帰が終了した時の処理
    if(dp[n][m].size()) return;
    
    if(n==1) {
        for(int i=1;i<=m;i++) dp[n][m].push_back({i});
    } else {
        // kの値（Sの最後の値）で全探索

        for(int k=1;k<=m;k++) {
            //必要条件
            if(n-1 <=k-1){
                solve(n-1,k-1);
                for(int i=0;i<dp[n-1][k-1].size();i++) {
                    vector<int> v = dp[n-1][k-1][i];
                    
                    v.push_back(k);
                    dp[n][m].push_back(v);
                }
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    solve(n,m);
    sort(all(dp[n][m]));
    for(int i=0;i<dp[n][m].size();i++) {
        for(int j=0;j<n;j++) {
            cout << dp[n][m][i][j] << " ";
        }
        cout << endl;
    }
}