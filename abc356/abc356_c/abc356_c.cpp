#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;

int main() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> c(m);
    vector<vector<int>> a(m);
    vector<int> r(m); 
    rep(i, 0, m) {
        cin >> c[i];
        a[i].resize(c[i]);
        rep(j, 0, c[i]) {
            cin >> a[i][j];
            a[i][j]--;
        }
        char x;
        cin >> x;
        if (x == 'o') {
            r[i] = 1;
        } else {
            r[i] = 0;
        }
    }

    for (int c = 0; c < (1 << n); c++) {
        vector<int> s(n);
        rep(i, 0, n) {
            if (c & (1 << i)) {
                s[i] = 1;
            } else {
                s[i] = 0;
            }
        }

        bool ok = true;
        rep(i, 0, m) {
            int cnt = 0;
            bool flag = true;
            rep(j, 0, a[i].size()) {
                if (s[a[i][j]]) {
                    cnt++;
                }
            }
            if (cnt < k && r[i]) {
                flag = false;
            }
            if (cnt >= k && !r[i]) {
                flag = false;
            }

            if (!flag) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
