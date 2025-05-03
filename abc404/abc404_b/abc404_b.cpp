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
using mint=modint998244353;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vector<string> t(n);
    rep(i, 0, n) cin >> t[i];
    int ans = (int)1e9;
    rep(k,0,4) {
        vector<string> u(n);
        rep(i, 0, n) {
            u[i] = string(n, ' ');
            rep(j, 0, n) {
                u[i][j] = s[n-1-j][i];
            }
        }
        int cnt = 0;
        rep(i, 0, n) {
            rep(j, 0, n) {
                if (u[i][j] != t[i][j]) cnt++;
            }
        }
        cnt += (k+1)%4;
        ans = min(ans, cnt);
        //swap(s,u);
        rep(i, 0, n) {
            rep(j, 0, n) {
                s[i][j] = u[i][j];
            }
        }
        //cout << "k = " << k << " cnt = " << cnt << endl;
        
    }
    cout << ans << endl;
}