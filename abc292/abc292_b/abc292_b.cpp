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
    int N,Q;cin>>N>>Q;
    vector<int> a(N,0);
    rep(i,Q) {
        int t,e;cin>>t>>e;
        e--;
        if(t==1) a[e]++;
        if(t==2) a[e]+=2;
        if(t==3) {
            if(a[e]>=2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

