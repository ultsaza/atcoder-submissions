#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using mint=modint998244353;
#define INF 1e18 
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


int main() {
    ll n,m;
    cin >> n >> m;
    set<ll> st;
    rep(i,0,m) {
        ll a; cin >> a;
        st.insert(a);
    }
    cout << n - m << endl;
    rep(i,1,n+1) {
        if (st.count(i)) continue;
        cout << i << " ";
    } cout << endl;
}