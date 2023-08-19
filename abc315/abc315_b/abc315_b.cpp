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
    int M;cin >> M;
    vector<int> D(M);
    rep(i,M) cin >> D[i];
    int sum=0;
    rep(i,M) sum+=D[i];
    int mid=sum/2+1; //真ん中のひ
    int crr=0;
    rep(i,M) {
        crr+=D[i];
        if(crr>=mid) {
            cout << i+1 << " "<< -crr+D[i]+mid;
            break;
        }
    }
}