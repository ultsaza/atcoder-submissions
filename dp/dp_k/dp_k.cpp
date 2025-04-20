#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using mint=modint1000000007;
#define INF 1e18
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

int main() {
    int n,k;
    cin >> n >> k;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    vector<bool> dp(k+1,false);
    rep(i,0,k+1) {
        bool ok = false;
        rep(j,0,n) {
            if (i-a[j] >= 0 && !dp[i-a[j]]) {
                ok = true;
                break;
            }
        }
        dp[i] = ok;
    }

    cout << (dp[k] ? "First" : "Second") << endl;
}