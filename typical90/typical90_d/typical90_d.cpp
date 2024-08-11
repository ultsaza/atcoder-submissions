#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, r) for (ll i = 0; i < (r); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    int h,w;
    cin >> h >> w;
    int a[h][w];
    rep(i, h) rep(j, w) cin >> a[i][j];
    int x[h] = {0};
    int y[w] = {0};
    rep(i, h) {
        rep(j, w) {
            x[i] += a[i][j];
        }
    }

    rep(j, w) {
        rep(i, h) {
            y[j] += a[i][j];
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << x[i] + y[j] - a[i][j] << " ";
        }
        cout << endl;
    }
}