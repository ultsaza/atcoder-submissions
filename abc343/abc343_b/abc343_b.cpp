#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const int INF = 0x3fffffff;
const ll LINF = 0x1ffffffffffffff;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> A[i][j];
            if (A[i][j] == 1)
            {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
}
