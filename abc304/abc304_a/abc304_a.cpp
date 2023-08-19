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
const ll LINF = 0x1fffffffffffffff;


int main(void) {
    int N; cin >> N;
    vector<pair<int,string>> A(N);
    rep(i,N) {
        cin >> A[i].second >> A[i].first;
    }
    int minacs=0;
    rep(i,N) {
        if(A[minacs].first > A[i].first) {
            minacs = i;
        }
    }
    rep(i,minacs,N) cout << A[i].second << '\n';
    rep(i,minacs) cout << A[i].second << '\n';
}
