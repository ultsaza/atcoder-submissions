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
    int  n,m; cin >> n >> m;
    vector<string> s(n); rep(i,n) cin >> s[i];
    sort(all(s));
    do{bool E=1;
        rep(i,n-1) {
            int cnt=0;
            rep(j,m) if(s[i][j]!=s[i+1][j]) cnt++;
            if(cnt!=1) E=0;
        }
        if(E) {
            cout << "Yes";
            return 0;
            }
    }while(next_permutation(all(s)));
    cout << "No";
}