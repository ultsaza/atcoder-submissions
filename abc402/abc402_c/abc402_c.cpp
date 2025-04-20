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
    vi r(m);
    vvi v(n);
    rep(i,0,m) {
        cin >> r[i];
        rep(j,0,r[i]) {
            int a;
            cin >> a;
            a--;
            v[a].push_back(i);
        }
    }
    int ans = 0;
    rep(i,0,n) {
        int b;
        cin >> b;
        b--;
        for (auto x: v[b]) {
            r[x]--;
            if (r[x] == 0) ans++;
        }
        cout << ans << endl;
    }
}