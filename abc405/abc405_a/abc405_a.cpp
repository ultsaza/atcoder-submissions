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
    int r,x;
    cin >> r >> x;
    if (x == 1) {
        if (r>=1600 && r <=2999){
            cout << "Yes" << endl;
            return 0;
        }
    } else {
        if (r>=1200 && r <=2399){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}