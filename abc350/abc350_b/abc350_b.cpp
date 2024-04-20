#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;

int main() {
    int N,Q;
    cin >> N >> Q;
    vector<int> T(N);
    rep(i,0,N) T[i] = 1;
    rep(i,0,Q) {
        int t;
        cin >> t;
        t--;
        if(T[t] == 1) {
            T[t] = 0;
        } else {
            T[t] = 1;
        }
    }
    int ans =0;
    rep(i,0,N) {
        if(T[i]) ans ++;
    }
    cout << ans << endl;
}