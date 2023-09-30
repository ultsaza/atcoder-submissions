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
    int N,M; string S,T;
    cin >> N >> M >> S >> T;
    bool pre=1,fore=1;
    rep(i,N) {
        if(S[i]!=T[i]) pre=0;
        //if(S[N-i-1]!=T[i]) fore=0;
    }
    reverse(all(S));
    reverse(all(T));
    rep(i,N){
        if(S[i]!=T[i]) fore=0;
    }
    rep(i,M)
    if(pre==1&&fore==1) {cout << 0;return 0;}
    if(pre==1&&fore==0) {cout << 1;return 0;}
    if(pre==0&&fore==1) {cout << 2;return 0;}
    if(pre==0&&fore==0) {cout << 3;return 0;}
}