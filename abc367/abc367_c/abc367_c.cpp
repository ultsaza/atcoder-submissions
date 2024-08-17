#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, r) for (ll i = 0; i < (r); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    rep(i, n) cin >> r[i];

    auto gen = [&] (auto& gen, vector<int>& v, int index, int sum) -> void {
        if (index == n) {
            if (sum % k == 0) {
                for (auto x : v) cout << x << " ";
                cout << endl;
            }
            return;
        }
        for (int i = 1; i <= r[index]; i++) {
            v.push_back(i);
            gen(gen, v, index + 1, sum + i);
            v.pop_back();
        }
    };

    vector<int> v;
    gen(gen, v, 0, 0);

    return 0;
}