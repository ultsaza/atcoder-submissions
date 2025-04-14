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
using mint=modint998244353;
#define INF 1e18 
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


int main() {

    deque<ll> dq;
    deque<ll> dq2;
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) {
        cin >> a[i];
    }
    sort(all(a));
    ll l =0 , r = n -1;
    rep(i,0,n) {
        if (i%4 == 0) {
            dq.push_back(a[l]);
            l++;
        } else if (i%4 == 1) {
            dq.push_front(a[r]);
            r--;
        } else if (i%4 == 2) {
            dq.push_back(a[r]);
            r--;
        } else {
            dq.push_front(a[l]);
            l++;
        }
    }
    l = 0;
    r = n -1;
    rep(i,0,n) {
        if (i%4 == 0) {
            dq2.push_back(a[r]);
            r--;
        } else if (i%4 == 1) {
            dq2.push_front(a[l]);
            l++;
        } else if (i%4 == 2) {
            dq2.push_back(a[l]);
            l++;
        } else {
            dq2.push_front(a[r]);
            r--;
        }
    }

    ll ans = 0;
    ll tmp1 = dq.front();
    ll tmp2;
    rep(i,0,n-1) {
        dq.pop_front();
        tmp2 = dq.front();
        ans += abs(tmp1 - tmp2);
        tmp1 = tmp2;
    }

    ll ans2 = 0;
    tmp1 = dq2.front();
    tmp2;
    rep(i,0,n-1) {
        dq2.pop_front();
        tmp2 = dq2.front();
        ans2 += abs(tmp1 - tmp2);
        tmp1 = tmp2;
    }   
    cout << max(ans, ans2) << endl;
}