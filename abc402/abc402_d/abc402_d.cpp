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
    vl v(2*n,0);
    rep (i,0,m) {
        ll a,b;
        cin >> a >> b;
        a--; b--;
        a *= 2;
        b *= 2;
        ll m = min(((a + b) / 2), ((a + b) / 2 + n)%(2*n));
        v[m]++;
    }
    //rep(i,0,2*n) {
    //    cout <<"i:" << i << " v:" << v[i] << endl;
    //}
    ll ans = -1;
    ll tmp = 0;
    bool flag = false;
    rep(i,0,2*n) {
        if(v[i] == 0) continue;
        if (ans == -1) {
            ans = 0;
            tmp = v[i];
        }
        else {
            if (flag) {
                ans = ans + tmp * v[i];
                tmp += v[i];
            }
            else {
                ans = tmp * v[i];
                tmp += v[i];
                flag = true;
            }
        }
    }
    if (m==1) {
        cout << 0 << endl;
    }
    else {
        cout << ans << endl;
    }


}