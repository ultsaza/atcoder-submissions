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
    int N,H,X; cin >> N >> H >> X;
    vector<pair<int,int>> P(N);
    rep(i,N){
        cin >> P[i].first;
        P[i].second = i;
    }
    vector<pair<int,int>> sub;
    rep(i,N) {
        if(H+P[i].first >= X) {
            sub.push_back(make_pair(P[i].first,P[i].second));
    }
    }
    sort(all(sub));
    cout << sub[0].second+1 << endl;
}