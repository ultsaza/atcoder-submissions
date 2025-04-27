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
    int n,m,q;
    cin >> n >> m >> q;
    vector<set<int>> s(n);
    rep(i,0,q) {
        int t;
        cin >> t;
        if(t == 1) {
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            s[x].insert(y);
        }
        else if(t == 2) {
            int x;
            cin >> x;
            x--;
            s[x].insert(-1);
        }
        else {
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            if (s[x].count(y) || s[x].count(-1)) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
            
}