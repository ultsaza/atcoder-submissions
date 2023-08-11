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
    string s; cin >>s; // a -> 97
    vector<bool> A(26,0);
    rep(i,s.size()) A[(int)s[i] - 97] = 1;
    bool B=1;
    rep(i,26) B = B & A[i];
    if(B) {
        cout << "None";
        return 0;
    } else {
        rep(i,26) if(!A[i]) {
            cout << (char)(i+97);
            return 0;
        }
    }
}