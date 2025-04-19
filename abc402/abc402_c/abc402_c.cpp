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
#define INF 1000000009
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    rep(i,0,m) {
        int k; cin >> k;
        rep(j,0,k) {
            int a; cin >> a;
            a--;
            v[a].push_back(i);
        }
    }
    vi b(n);
    rep(i,0,n) {
        cin >> b[i];
        b[i]--;
    }
    reverse(all(b));
    vi ans(n);

    set<int> st;
    rep(i,0,n) {  
        ans[i] = m - st.size();
        rep(j,0,v[b[i]].size()) {
            st.insert(v[b[i]][j]);
        }
        
    }
    reverse(all(ans));
    rep(i,0,n) cout << ans[i] << endl;
}