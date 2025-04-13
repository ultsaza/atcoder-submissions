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
    int n;
    cin >> n;
    vi poly(1000001, 0);
    rep(i, 0, n) {
        int a; cin >> a;
        poly[a] = 1;
    }
    vi mult = convolution(poly, poly);
    ll ans = 0;
    rep(i, 0, 1000001) {
        if (!poly[i]) continue;
        ans += (mult[2*i]-1)/2;
    }
    cout << ans << endl;
   
        
}