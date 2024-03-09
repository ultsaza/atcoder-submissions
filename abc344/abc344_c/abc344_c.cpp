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


int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    int M; cin >> M;
    vector<ll> B(M);
    rep(i,M) cin >> B[i];
    int L; cin >> L;
    vector<ll> C(L);
    rep(i,L) cin >> C[i];
    ll Q; cin >> Q;
    vector<ll> sumA_B(N*M);
    rep(i,N) rep(j,M) sumA_B[i*M+j] = A[i] + B[j];
    sort(all(sumA_B));
    rep(_,Q) {
        bool flag = false;
        int x; cin >> x;
        rep(c,L) {
            ll target = x - C[c];
            ll pos = lower_bound(all(sumA_B), target) - sumA_B.begin();
            if(pos < N*M && sumA_B[pos] == target) {
                flag = true;
            }
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}