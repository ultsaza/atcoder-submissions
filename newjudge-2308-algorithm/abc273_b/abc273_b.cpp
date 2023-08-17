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
    ll X,K; cin>>X>>K;
   rep(i,K) {
    ll div = pow(10,i);
    ll r = (X/div)%10;
    if(r<5) {
        X -= r*pow(10,i);
    } else {
        X -= r*pow(10,i);
        X += pow(10,i+1);
    }
    //cout<<X<<" "<<r<<'\n';
   }
   cout<<X<<'\n';
//314000000000000
//314000000000000
}