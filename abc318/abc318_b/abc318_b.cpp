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
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;

int main() {
    int N; cin >> N;
    int ans=0;
    bool seal[109][109];
    rep(i,101)rep(j,101) {
        seal[i][j]=0;
    }
    rep(i,N) {
        int a,b,c,d; cin >> a >> b >> c >> d ;
        rep(i,a,b) rep(j,c,d) {
            seal[i][j]=1;
        }
    }
    rep(i,101)rep(j,101) {
        if(seal[i][j]) ans++;
    }
    cout << ans << '\n';
}