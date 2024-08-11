#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ll n, l, k;
    cin >> n >> l >> k;
    ll a[n];
    rep(i, 0, n) {
        cin >> a[i];
    }
    ll b[n + 1];
    b[0] = a[0];
    rep(i, 1, n) {
        b[i] = a[i] - a[i - 1];
    }
    b[n] = l - a[n - 1];

    ll left = -1, right = (int)1e9 + 1, mid;
    while(right - left > 1) {
        mid = (left + right) / 2;
        int count = 0;
        ll cur = 0;
        rep(i, 0, n + 1) {
            cur += b[i];
            if(cur >= mid) {
                cur = 0;
                count++;
            }
        }
        if(count > k) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << endl;
}