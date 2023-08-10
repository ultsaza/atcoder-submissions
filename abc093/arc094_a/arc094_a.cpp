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

int main(void) {
    vector<int> v(3);
    rep(i,3) cin >> v[i];
    sort(all(v));
    int eA=0,oA=0;
    vector<int> E(3);
    vector<int> O(3);
    rep(i,3) {
        E[i]=v[i];
        O[i]=v[i];
    }
    rep(i,3) {
        if(E[i]%2==1) {E[i]--; eA++;}
        if(O[i]%2==0) {O[i]--; oA++;}
    }
    eA+=(2*E[2]-E[1]-E[0])/2;
    oA+=(2*O[2]-O[1]-O[0])/2;
    cout << min(eA,oA);
}