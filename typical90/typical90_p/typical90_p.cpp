#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, r) for (ll i = 0; i < (r); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll cur = 10000;
    rep(i, 10000) {
        rep(j, 9999) {
            if((a * i + b * j - n) % c != 0 || a * i + b * j - n > 0) {
                continue;
            }
            cur = min(cur, i + j + (-a * i - b * j + n)/(c));
        }
    }
    cout << cur;
}
