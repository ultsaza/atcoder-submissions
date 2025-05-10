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
using mint=modint1000000007;

int main() {
    int n,m;
    cin >> n >> m;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    int id = 0;
    rep(k,0,n) {
        set<int> st;
        rep(i,0,n - k) {
            st.insert(a[i]);
        }
        if (st.size() != m) {
            cout << k << endl;
            return 0;
        }
    }
    cout << n << endl;
   
    
}