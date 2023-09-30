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



int main() {
    int N,X; cin >> N >> X;
    vector<int> A(N-1);
    rep(i,N-1) cin >> A[i];
    int m = *min_element(all(A));
    int M = *max_element(all(A));
    auto S = A;
    sort(all(S));
    int allsum = accumulate(all(A),0);
    if(allsum-M>=X) {
        cout << 0 << endl;
        return 0;
    }
    else if(X-(allsum-m-M)>=0 && X-(allsum-m-M)<=100) {
        if(m <=X-(allsum-m-M) && M>=X-(allsum-m-M)){ cout << X-(allsum-m-M) << endl;
        return 0;
        }
    }
    if(allsum-m>=X) {
        cout << m << endl;
        return 0;
    }
    cout << -1 << endl;
}