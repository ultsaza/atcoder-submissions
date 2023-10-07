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
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    vector<pair<int,int>> P(N);
    rep(i,N) {
        P[i].second = i+1;
        P[i].first = 0;
    }
    rep(i,N) {
        rep(j,i,N) {
            if(i==j) continue;
            if(S[i][j]=='o') {
                P[i].first++;
            }
            if(S[i][j]=='x') {
                P[j].first++;
            }
        }
    }
    for(int win=100;win>=0;win--) {
        rep(i,N) {
            if(P[i].first==win) {
                cout << P[i].second << " ";
            }
        }
    }
}