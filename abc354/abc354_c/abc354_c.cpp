#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;

int main() {
    int N;
    cin >> N;
    vector<pair<pair<int, int>, int>> S(N); // {{first, second}, index}
    rep(i, 0, N) {
        cin >> S[i].first.first >> S[i].first.second;
        S[i].second = i; // 保存元のインデックス
    }
    sort(all(S), [](const auto &a, const auto &b) {
        return a.first > b.first;
    });

    vector<int> ans;
    int siz = 0;
    int pre = (int)1e9 + 9;
    rep(i, 0, N) {
        if (S[i].first.second < pre) {
            siz++;
            pre = S[i].first.second;
            ans.push_back(S[i].second); // 元のインデックスを保存
        }
    }

    sort(all(ans));

    cout << siz << endl;
    for (auto a : ans) {
         cout << a + 1<< " ";
    }
    cout << endl;
}
