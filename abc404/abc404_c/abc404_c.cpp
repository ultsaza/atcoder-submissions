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
    vvi G(n);
    dsu uf(n);
    rep(i,0,m) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        uf.merge(a,b);
    }
    rep(i,0,n) {
        if (G[i].size() != 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    if(uf.size(0) != n) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    
}