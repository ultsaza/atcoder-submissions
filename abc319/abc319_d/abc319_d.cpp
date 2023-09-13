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
    int N,M; cin >> N >> M;
    vector<ll> L(N);
    rep(i,N) {
        cin >> L[i];
        L[i]++;
    }
    ll lower= *max_element(all(L)) -1; //各単語で改行
    ll upper= accumulate(all(L),0LL);///改行なし

    while(lower+1 < upper) {
        ll mid = (upper+lower)/2;
        /*
        もし答えがmidより大きかったら
        midを答えとして仮定すると途中ではみ出さざるを得なくなる

        また不必要な改行をする解は最適解になり得ない
        */
        int rows =1;
        ll len = 0;
        rep(i,N) {
            len += L[i];
            if(len>mid) { //答えを仮定して進めてる
                rows++;
                len = L[i];
            }
        }
        if(rows > M) lower = mid;
        else upper = mid;
    }
    cout << upper-1;
}
