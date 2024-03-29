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
    int n;
    cin >> n;
    map<ll,ll> cnt;
    vector<int> a(n);
    rep(n) cin >> a[i];

    vector<ll> prex(n+1);
    prex[0] = 0;
    cnt[0] = 1;
    rep(n) {
        prex[i+1] = prex[i] + a[i];
        cnt[prex[i+1]]++;
    }

    //prex[r] - prex[l-1] ==0

    ll ans =0;

    for(auto [key,value] : cnt) {
        ans += value * (value-1) / 2;
    }
    cout << ans << '\n';
}