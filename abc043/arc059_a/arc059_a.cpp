#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;

int cost(int x, int y) {
    return (x-y)*(x-y);
}
int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> C;
    for(int i=-100;i<=100;i++) {
        int sum = 0;
        rep(j, N) {
            sum += cost(A[j], i);
        }
        C.push_back(sum);
    }
    sort(all(C));
    cout << C[0];
}