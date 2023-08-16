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
const ll LINF = 0x1fffffffffffffff;

int main(void) {
    int N; cin >> N;
    vector<vector<int>> A(N);
    rep(i,N) {
        int c; cin >> c;
        rep(j,c) {
            int a; cin >> a;
            A[i].push_back(a);
        }
    }
    vector<int> hasX;
    int X; cin >> X;
    rep(i,N) {
        rep(j,A[i].size()) {
            if(A[i][j]==X) {
                hasX.push_back(i);
                break;
            }
        }
    }
    int minbet=10000000;//inf
    rep(i,hasX.size()) {
        minbet=min(minbet,(int)(A[hasX[i]]).size());
    }
    vector<int> ans;
    rep(i,hasX.size()) {
        if(A[hasX[i]].size()==minbet) ans.push_back(hasX[i]);
    }
    cout << ans.size() << '\n';
    rep(i,ans.size()) cout << ans[i]+1 << " ";

}
    