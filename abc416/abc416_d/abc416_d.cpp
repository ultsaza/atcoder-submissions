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
#define INF 1e18
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n,m;
        ll sum = 0;
        cin >> n >> m;
        vl a(n), b(n);
        rep(i, 0, n) {
            cin >> a[i];
            sum += a[i];
        }
        rep(i, 0, n) {
            cin >> b[i];
            sum += b[i];
        }
        sort(all(a));
        sort(all(b));
        vl c(n);
        rep(i, 0, n) {
            c[i] = m - b[i];
        }
        sort(all(c));
        ll cnt = 0;
        ll i = 0, j = 0;
        while (i < n && j < n) {
            if (a[i] >= c[j]) {
                i++;
                j++;
                cnt++;
            } else {
                i++;
            }
        }
        cout << sum - m * cnt << endl;

    }
}
