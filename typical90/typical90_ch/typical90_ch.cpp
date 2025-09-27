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
#define INF 4*10e18
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint = modint1000000007;

int main() {
    ll n, q;
    cin >> n >> q;
    vl x(q),y(q),z(q),w(q);
    rep(i,0,q) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        x[i]--;
        y[i]--;
        z[i]--;
    }
    mint ans = 1;
    rep(m,0,60) {
        mint v = 0;
        rep(k,0,(1<<(n))) {
            bool flag = 1;
            rep(i,0,q){
                if (((w[i]>>m)&1) != (((k>>x[i])&1)|((k>>y[i])&1)|((k>>z[i])&1))) {
                    flag = 0;
                }
            }
            v += flag;
        } 
        ans *= v;
    }
    cout << ans.val() << endl;
}