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


void solve() {
    int n; cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) {
        cin >> a[i] >> b[i];
    }
    auto cmp = [&](int i, int j) {
        ll vl = a[i] * (a[j] + b[j]);
        ll vr = a[j] * (a[i] + b[i]);
        if(vl != vr) return vl > vr;
        else return i<j;
    };
    vector<int> ids(n);
    iota(all(ids), 0);
    sort(all(ids), cmp);
    rep(i,n) cout << ids[i] +1 << " ";
}
int main() {
    solve();
}