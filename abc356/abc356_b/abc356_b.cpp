#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;


int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m),b(m);
    rep(i,0,m) {
        cin >> a[i];
    }
    ll x[n][m];
    rep(i,0,n) rep(j,0,m) {
        cin >> x[i][j];
        b[j] += x[i][j];
    }

    rep(i,0,m) {
        if(b[i] < a[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}