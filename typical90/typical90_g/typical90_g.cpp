#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, r) for (ll i = 0; i < (r); ++i)
#define all(x) (x).begin(), (x).end()
constexpr int INF = 1000000000;

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    sort(all(a));
    int q;
    cin >> q;
    while(q--) {
        ll b;
        cin >> b;

        ll j = lower_bound(all(a), b) - a.begin();

        ll ret = INF;
        if(j < N) {
            ret = min(ret, abs(b - a[j]));
        }
        if(j > 0) {
            ret = min(ret, abs(b - a[j - 1]));
        }
        cout << ret << endl;
    }

}
