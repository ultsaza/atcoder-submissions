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
const ll INF = 1e18;


int main() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<mint> fact(a+b+c+d+1);
    fact[0] = 1;
    rep(i,1,a+b+c+d+1) {
        fact[i] = fact[i-1] * i;
    }
    mint ans = 0;
    rep(i,0,c+1) {
        ans += fact[a+b+i] * fact[d-1+c-i] * ((fact[b] * fact[a+i] * fact[d-1] * fact[c-i]).inv());
    }
    cout << ans.val() << endl;
    
}