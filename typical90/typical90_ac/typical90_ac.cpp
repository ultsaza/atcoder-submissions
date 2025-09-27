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
using mint=modint998244353;

using S = ll;
using F = ll;
S op(S l, S r) { return max(l, r); }
S e() {return 0;}
S mapping(F l, S r) {return max(l, r);}
F composition(F l, F r) {return max(l,r);}
F id() {return 0;}

int main() {
    ll w, n; 
    cin >> w >> n;
    lazy_segtree<S,op,e,F,mapping,composition,id> seg(w+1);
    rep(i,0,n) {
        ll l,r;
        cin >> l >> r;
        l--;r--;
        ll h = seg.prod(l, r+1);
        cout << h+1 << endl;
        seg.apply(l,r+1,h+1);
    }
}