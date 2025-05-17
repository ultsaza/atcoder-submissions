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
    int n;
    cin >> n;
    vi p(n+1,-1);
    rep(i,0,n) cin >> p[i];

    ll ans = 0;
    ll len_prev = 0, len_now = 0;
    bool is_up = (p[0] < p[1]);
    rep(i,0,n) {
        if (is_up) {
            if (p[i+1] > p[i]) {
                len_now++;
            } else {
                ans += len_prev * len_now;
                is_up = !is_up;
            }
        } else {
            if (p[i+1] < p[i]) {
            } else {
                len_prev = len_now;
                len_now = 1;
                is_up = !is_up;
            }
        }
    }
    cout << ans << endl;
}
