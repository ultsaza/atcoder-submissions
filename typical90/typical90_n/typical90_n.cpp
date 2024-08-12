#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, r) for (ll i = 0; i < (r); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N; 
    vector<int> a(N);
    vector<int> b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    sort(all(a));
    sort(all(b));

    ll ans = 0;

    rep(i, N) {
        ans += abs(a[i] - b[i]);
    }

    cout << ans;

}

