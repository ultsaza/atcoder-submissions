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
    int n; cin >> n;
    vector<pair<int,int>> ab;
    rep(i,n) {
        int a,b; cin >> a >> b;
        ab.emplace_back(a,a+b);
    }
    vector<int> p(n);
    iota(all(p),0);
    auto f = [&](int i,int j) {
        auto [ai,aj] = ab[i];
        auto [bi,bj] = ab[j];
        return (ll)ai*bj > (ll) aj*bi;
    };
    stable_sort(all(p),f);
    rep(i,n) cout << p[i]+1 << " ";
}




