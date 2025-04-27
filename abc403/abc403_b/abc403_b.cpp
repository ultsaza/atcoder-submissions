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
    string s;
    cin >> s;
    string u;
    cin >> u;
    ll n = s.size();
    ll m = u.size();
    rep (i,0,n-m+1) {
        rep(j,0,m) {
            if (s[i+j]!=u[j] && s[i+j] !='?')break;
            if(j==m-1) {
            cout << "Yes" << endl;
            return 0;
        }
        }
        
    }
    cout << "No" << endl;
    return 0;
}