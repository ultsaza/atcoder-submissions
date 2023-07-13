#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define all(v) v.begin(), v.end()
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
const ll LINF = 0x1fffffffffffffff;

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> s(m,vector<int> ());
    rep(i,m) {
        int c; cin >> c;
        rep(j,c) {
            int a; cin >> a;
            s[i].push_back(a);
        }
    }
    int ans=0;
    rep(i,1<<m) {
        vector<bool> B(n);
        rep(x,1,n+1) rep(j,m) if(i>>j & 1) rep(k,s[j].size()) if(s[j][k]==x) B[x-1]=1;
        bool bsum=1;
        rep(i,n) bsum = bsum & B[i];
        if(bsum) ans++;
    }
    cout << ans;
}