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
    int N; cin >> N;
    vector<vector<int>> A(N+1,vector<int> (N+1));
    vector<vector<int>> B(N+1,vector<int> (N+1));
    rep(i,1,N+1) rep(j,1,N+1) cin >> A[i][j];
    rep(i,1,N+1) rep(j,1,N+1) cin >> B[i][j];
    auto rotA = A;
    bool flag;
    bool ans = false;
    rep(_,4) {
        A=rotA;
        flag = true;
        rep(i,1,N+1) rep(j,1,N+1){
            if(rotA[i][j]==1) {if(B[i][j]==0) {flag=false;}}
        }
        ans = ans || flag;
        rep(i,1,N+1) rep(j,1,N+1) {rotA[i][j]=A[N+1-j][i];}
        //if(ans) cout << "Yes" << endl;
    //else cout << "No" << endl;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    // rot res[i][j] = A[N+1-j][i]
}