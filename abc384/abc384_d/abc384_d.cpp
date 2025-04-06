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
#define INF 1e18
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;


int main() {
    ll n,s;
    cin >> n >> s;
    vl a(n);
    rep(i,0,n) cin >> a[i];
    ll sum_a;
    sum_a = accumulate(all(a),0LL);
    ll res = s - sum_a * (s/sum_a);
    vl a_2(2*n);
    rep(i,0,n) {
        a_2[i] = a[i];
        a_2[i+n] = a[i];
    }
    // 尺取法により a_2の部分和でresと一致するものが存在するか探す

    ll l = 0, r = 0;
    ll sum = 0;
    bool ok = false;
    while (r < 2*n) {
        if (sum < res) {
            sum += a_2[r];
            r++;
        } else if (sum > res) {
            sum -= a_2[l];
            l++;
        } else {
            ok = true;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;

}