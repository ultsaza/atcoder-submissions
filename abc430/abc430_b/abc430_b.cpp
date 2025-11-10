#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint=modint1000000007;



int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,0,n) cin >> s[i];
    set<string> st;
    rep(i,0,n-m+1) rep(j,0,n-m+1) {
        string p;
        rep(k,0,m) rep(l,0,m) {
            p.push_back(s[i+k][j+l]);
        }
        st.insert(p);
    }
    cout << st.size() << endl;
}


