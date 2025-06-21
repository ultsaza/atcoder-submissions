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
    vl d(n+1, 0);
    rep(i, 1, n) {
        cin >> d[i];
    }
    vl s(n+1, 0);
    rep(i, 1, n) {
        s[i] = s[i-1] + d[i];
    }
    rep(i,1,n) {
        rep(j,i,n) {
            cout << s[j] - s[i-1] << " ";
        }
        cout << endl;
    }
}
