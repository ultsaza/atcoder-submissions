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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint=modint1000000007;
const ll INF = 1e18;

int main() {  
    int t; cin >> t;
    while (t--) {
        bool flag = false;
        int n; cin >> n;
        if (n==2) {
            flag = true;
        }
        vector<ll> a(n);
        rep(i,0,n) cin >> a[i];
        sort(all(a));
        rep(i,1,n-1) {
            if (a[i]*a[i] != a[i-1]*a[i+1]) {
                break;
            }
            if (i == n-2) {
                flag = true;
            }
        }
        vector<pair<ll,ll>> b(n);
        set<ll> st;
        rep(i,0,n) {
            b[i] = {abs(a[i]), a[i]};
            st.insert(a[i]);
        }
        sort(all(b));
        rep(i,1,n-1) {
            if (b[i].second * b[i].second != b[i-1].second * b[i+1].second) {
                break;
            }
            if (i == n-2) {
                flag = true;
            }
        }
        int cnt = 0;
        if (st.size() == 2) {
            rep(i,0,n) {
                if (a[i] == a[0]) {
                    cnt++;
                } else {
                    if (a[i] != -a[0]) {
                        cnt = n;
                        break;
                    }
                }
            }
            if ((n%2 == 0 && cnt == n/2) || (n%2 == 1 && (cnt == n/2|| cnt == n/2 + 1))) {
                flag = true;
            }
        }
        

        cout << (flag ? "Yes" : "No") << endl;

    }
}
