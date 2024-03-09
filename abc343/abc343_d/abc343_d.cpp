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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,t;
    cin >> n >> t;
    vector<ll> score(n);
    map<ll,int> mp;
    mp[0]=n;
    rep(i,t) {
        int a,b;
        cin >> a >> b;
        a--;
        if(--mp[score[a]] ==0) mp.erase(score[a]);
        score[a]+=b;
        ++mp[score[a]];
        cout << mp.size() << endl;
    }
}