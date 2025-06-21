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
const ll INF = 1e18;

int main() {
    int n,q;
    cin >> n >> q;
    vector<bool> d(n+2, false);
    int ans = 0;
    while(q--) {
        int a;
        cin >> a;
        if (!d[a]) { // a番目塗られてない.
            d[a] = true;
            if (d[a-1] && d[a+1]) ans--;
            else if (d[a-1] || d[a+1]) ;
            else ans++;
        } else {
            d[a] = false;
            if (d[a-1] && d[a+1]) ans++;
            else if (d[a-1] || d[a+1]) ;
            else ans--;
        }
        cout << ans << endl;
    }
}
