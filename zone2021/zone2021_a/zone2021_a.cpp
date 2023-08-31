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
    string S;
    cin >> S;
    int ans = 0;
    if(S.substr(0, 4) == "ZONe") ans++;
    if(S.substr(1, 4) == "ZONe") ans++;
    if(S.substr(2, 4) == "ZONe") ans++;
    if(S.substr(3, 4) == "ZONe") ans++;
    if(S.substr(4, 4) == "ZONe") ans++;
    if(S.substr(5, 4) == "ZONe") ans++;
    if(S.substr(6, 4) == "ZONe") ans++;
    if(S.substr(7, 4) == "ZONe") ans++;
    if(S.substr(8, 4) == "ZONe") ans++;
    cout << ans << endl;
}