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
    int N; cin >> N;
    vector<pair<int,int>> P(N);
    rep(i,N) cin >> P[i].second >> P[i].first;
    sort(all(P));
    reverse(all(P));
    //SmaxはP[0].first
    //rep(i,N) cout << P[i].first << " " << P[i].second <<'\n';
    int dff=0;
    int sam=0;
    rep(i,1,N) {
        if(P[0].second != P[i].second) {
            dff = P[0].first + P[i].first;
            break;
        }
    }
    rep(i,1,N) {
        if(P[0].second == P[i].second) {
            sam = P[0].first +((P[i].first)/2);
            break;
        }
    }

    //cout << "dif:" << dff << " sam:" << sam << endl;
    cout << max(sam,dff) << endl;
}