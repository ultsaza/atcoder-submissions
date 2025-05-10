#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using ld = long double;
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;
const ll INF = 1e18;


int main() {
    string s;
    cin >> s;
    vector<ll> c(26,0);
    ll ans = 0;
    c[s[0]-'a']++;

    rep(i,1,s.size()) {
        rep(j,0,26) {
            if(j == s[i]-'a') {
                continue;
            }
            if (c[j]) ans+=c[j];
        }   
        c[s[i]-'a']++;
    }
    bool ok = false;
    rep(i,0,26) {
        if (c[i] > 1) ok = true;
    }
    cout << ans + (ok ? 1 : 0) << endl;

}