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
    ll n, m;
    cin >> n >> m;
    set<pl> st;
    ll ans = 0;
    rep(i, 0, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        if (st.count(pl(a,b))) {
            ans++;
        } else if(a == b) {
            ans++; continue;
        }
        st.insert(pl(a,b));
    }
    

    cout << ans << endl;
}