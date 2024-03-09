#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const int INF = 0x3fffffff;
const ll LINF = 0x1ffffffffffffff;

int main() {
    int n; cin >> n;
    map<int,int> mp;
    rep(i,n) {
        int p; cin >> p;
        mp[p] = i+1;
    }
    int q; cin >> q;
    
    rep(_,q) {
        int a,b;
        cin >> a >> b;
        if(mp[a] > mp[b]) {
            cout << b << endl;
        } else {
            cout << a << endl;
        }
    }
}
