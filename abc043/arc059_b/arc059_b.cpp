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

int main(void) {
    string s;cin >> s;
    int n = s.size();
    rep(i,n-1) {
        if(s[i] == s[i+1]) {
            cout << i+1 << " " << i+2;
            return 0;
        }
    }
    rep(i,n-2) {
        if(s[i]==s[i+2]) {
            cout << i+1 << " " << i+3;
            return 0;
        }
    }
    cout << -1 << " " << -1;
    return 0;
}