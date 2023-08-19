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
    int H,W,N; cin>>H>>W>>N;
    vector<int> A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];
    //A=(1,1,3,9,1) ->(1,1,2,3,1) のように座標圧縮
    vector<int> A2;
    vector<int> B2;
    A2=A;B2=B;
    sort(all(A2));sort(all(B2));
    A2.erase(unique(all(A2)),A2.end());
    B2.erase(unique(all(B2)),B2.end());
    rep(i,N) {
        int x=lower_bound(all(A2),A[i])-A2.begin();
        int y=lower_bound(all(B2),B[i])-B2.begin();
        cout << x+1 << " " << y+1 << '\n';
    }
}
