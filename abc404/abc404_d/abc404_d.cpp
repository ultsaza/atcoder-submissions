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
    int n,m;
    cin >> n >> m;
    vi cost(n);
    vi k(m);
    vvi a(m);
    map<int,vi> mp;
    rep(i,0,n) cin >> cost[i];
    rep(i,0,m) {
        cin >> k[i];
        a[i].resize(k[i]);
        rep(j,0,k[i]) {
            cin >> a[i][j];
            mp[a[i][j]].push_back(i);
        }
    }
    ll ans = (ll)1e18;
    rep(i,0, pow(3,n)) {
        ll tmp = i;
        ll cost_sum = 0;
        vector<int> cnt(m,0);
        rep(j,0,n) {
            rep(l,0,tmp%3) {
                for(auto x: mp[j+1]) {
                    cnt[x]++;
                }
                cost_sum += cost[j];
            }
            tmp /= 3;
        }
        bool flag = true;
        rep(j,0,m) {
            if (cnt[j] < 2) flag = false;
        }
        if (flag) ans = min(ans,cost_sum);
    }
    cout << ans << endl;
}