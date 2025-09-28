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
    map<ll, ll> mp;
    vector<ll> p(n);
    set<ll> s;
    rep(i,1,n+1) s.insert(i);
    rep(i,0,n) {
        ll a;
        cin >> a;
        mp[a]++;
        if (mp[a] > 1 && a != -1) {
            cout << "No" << endl;
            return 0;
        }
        p[i] = a;
        if (a != -1) {
            s.erase(a);
        }
    }
    ll i = 0;
    for (auto x: s) {
        while(1) {
            if (p[i] == -1) {
                p[i] = x;
                i++;
                break;
            }
            i++;
        }
    }
    cout << "Yes" << endl;
    for(auto x: p) {
        cout << x << " ";
    }
}
  