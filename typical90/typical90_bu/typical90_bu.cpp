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
    ll n;
    cin >> n;
    vl c(n);
    rep(i,0,n) {
        char ch;
        cin >> ch;
        c[i] = (ch=='a')?0:1;
    }
    vvl g(n);
    rep(i,0,n-1) {
        ll a,b;
        cin >> a >> b;
        a--; b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<vector<mint>> dp(n, vector<mint> (3, 0));
    auto dfs = [&](auto self, ll v, ll p) -> void {
        mint s1 = 1, s2 = 1;
        for (auto nv: g[v]) {
            if (nv == p) continue;
            self(self, nv, v);
            s2 *= (dp[nv][c[v]]+dp[nv][2]);
            s1 *= (dp[nv][0]+dp[nv][1]+2*dp[nv][2]);
        }
        dp[v][c[v]] = s2;
        dp[v][2] = s1- s2;
    };
    dfs(dfs, 0 , -1);
    cout << dp[0][2].val() << endl;
}