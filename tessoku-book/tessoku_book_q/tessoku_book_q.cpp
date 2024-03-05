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



int main() {
    int N;
    cin >> N;
    int A[100009],B[100009];
    vector<int> dp(100009,0);
    vector<int> ans;
    rep(i,2,N+1) cin >> A[i];
    rep(i,3,N+1) cin >> B[i];
    dp[1]=0;
    dp[2]=A[2];
    rep(i,3,N+1) dp[i]=min(dp[i-1]+A[i],dp[i-2]+B[i]);

    int P=N;
    while(1) {

        ans.push_back(P);
        if(P==1) break; 
        if(P==2) {
            ans.push_back(1);
            break;
        }
        if(dp[P-1]+A[P]<=dp[P-2]+B[P]) P--;
        else P-=2;
        
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i]++ << " ";

}