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
    int n,m_g;
    cin >> n >> m_g;
    vvi G(n, vi(n, 0));
    rep(i,0,m_g){
        int u,v;
        cin >> u >> v;
        u--;v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    int m_h;
    cin >> m_h;
    vvi H(n, vi(n, 0));
    rep(i,0,m_h){
        int u,v;
        cin >> u >> v;
        u--;v--;
        H[u][v] = 1;
        H[v][u] = 1;
    }
    vvi a(n, vi(n, 0));
    rep(i,0,n)rep(j,i+1,n) {
        int x;
        cin >> x;
        a[i][j] = x;
        a[j][i] = x;
    }
    
    vi p(n);
    rep(i,0,n) p[i] = i;
    ll ans = INF;
    do {
        ll tmp = 0;
        rep(i,0,n)rep(j,0,n) {
            if (G[p[i]][p[j]] != H[i][j]) {
                tmp += a[i][j];
            }
        }
        tmp /= 2;
        ans = min(ans, tmp);
    } while(next_permutation(all(p)));
    cout << ans << endl;
}