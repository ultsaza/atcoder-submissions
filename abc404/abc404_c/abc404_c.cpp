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

int main() {
    int n,m;
    cin >> n >> m;
    dsu uf(n);
    vi deg(n,0);
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        u--;v--;
        uf.merge(u,v);
        deg[u]++;
        deg[v]++;
    }
    if (uf.size(0) != n) {
        cout << "No" << endl;
        return 0;
    }
    rep(i,0,n){
        if(deg[i]!=2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}