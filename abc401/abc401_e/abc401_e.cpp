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
    ll n,m;
    cin >> n >> m;
    vvl in(n), out(n);
    rep(i,0,m) {
        ll u,v; cin >> u >> v;
        u--; v--;
        in[max(u,v)].push_back(min(u,v));
        out[min(u,v)].push_back(max(u,v));
    }
    //? out[i]の頂点は必ず削除しなければならない
    //? in[i]の頂点は全て0と同じ連結成分に入っていなければならない

    dsu uf(n);
    set<ll> be_erase;
    rep(i,0,n) {
        if(be_erase.count(i)) be_erase.erase(i);
        for(auto j : in[i]) {
            uf.merge(i,j);
        }
        for(auto j : out[i]) {
            be_erase.insert(j);
        }
        //? ufは単一の連結成分
        if(uf.size(0) != i+1) {
            cout << -1 << endl;
        } else {
            cout << be_erase.size() << endl;
        }
    }

}