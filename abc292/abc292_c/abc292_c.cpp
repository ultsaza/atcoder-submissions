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

//x+y=Nの整数問題とみなす
//xを構成するA,Bの構成方法はxの正の約数だけ
//素数判定がO(sqrt(N))だから間に合うかも


int div(int n) {
    int out=0;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0) {
            out++;
        }
    }
    out*=2;

    if(sqrt(n)==floor(sqrt(n))) {
        out--;
    }
    return out;
}
int main() {
    int N; cin >> N;
    ll ans=0;
    rep(i,1,N){
        ans += div(i)*div(N-i);
    }
    cout << ans;
}

