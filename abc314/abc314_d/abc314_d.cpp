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
const ll LINF = 0x1fffffffffffffff;


int main(void) {
    ll N,Q;string S; cin >> N >> S >> Q;
    vector<ll> change(N,0);// S[i]が何回目のQueryで置換されたか　初めは0
    ll captype=0; //全体の操作　操作なしは0,sは2,Lは3 
    ll cap=0;//全体の操作を最後に施したのは何回目のQueryか

    rep(i,Q) {
        int t,x; char c; cin >> t >> x >> c;
        if(t==1) {
            change[x-1]=i+1;
            S[x-1]=c;
        }
        if(t==2) {
            captype=2;
            cap=i+1;
        }
        if(t==3) {
            captype=3;
            cap=i+1;
        }
    }
    string ans="";
    rep(i,N) {
        if(cap<change[i]) {
            ans+=S[i];
        } else {
            if(captype==2) ans += (char)tolower(S[i]);
            if(captype==3) ans += (char)toupper(S[i]);
            if(captype==0) ans += S[i];
        }
    }
    cout << ans << '\n';
}