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
    cin>>n>>m;
    vvl G(n);   
    vl a(m);
    rep(i,0,m){
        int x;
        cin>>x;
        a[i] = x-1;
    }
    vl b(m);
    rep(i,0,m){
        int x;
        cin>>x;
        b[i] = x-1;
    }
    two_sat ts(n);
    rep(i,0,m){
        ts.add_clause(a[i],true,b[i],true);
        ts.add_clause(a[i],false,b[i],false);
    }
    cout << (ts.satisfiable() ? "Yes" : "No") << endl;
}