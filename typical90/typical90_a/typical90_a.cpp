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
    ll N,L,K;
    cin >> N  >> L >> K;

    vector<ll> A(N);
    rep(N) cin >> A[i];
    vector<ll> P(N+1);
    P[0] = A[0];
    P[N] = L - A[N-1];
    rep(i,N-1) {
        P[i+1] = A[i+1] - A[i];
    }

    ll l=0, r = 1e9;

    while(abs(l-r)>1) {
        ll mid = (l+r)/2;

        //全ての切断がmid以上にできるかを判定

        ll cur =0,cnt = 0;

        rep(i,N+1) {
            cur += P[i];
            if(cur >= mid) {
                cnt ++;
                cur = 0;
            }
        }
        if(cnt>=K+1) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;
}