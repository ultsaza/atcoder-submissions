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
    vector<int> class1(N+1),  class2(N+1);
    class1[0]=0;class2[0]=0;
    rep(i,N) {
        int c,b; cin >> c >> b;
        if(c==1) {
            class1[i+1]=class1[i]+b;
            class2[i+1]=class2[i];
        }
        else{
            class1[i+1]=class1[i];
            class2[i+1]=class2[i]+b;
        }
    }
    int q; cin >> q;
    rep(i,q) {
        int l,r; cin >> l >> r;
        cout <<class1[r] - class1[l-1] <<" "<< class2[r] - class2[l-1] << '\n';
    }
}