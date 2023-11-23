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
const ll LINF = 0x1ffffffffffffff;
int main() {
    int N;
    string S;
    int ans = 0;
    cin >> N >> S;
    vector<int> max_len(26,0);
    char tmp = S[0];
    int cur = 0;
    rep(i,N) {
        if(tmp == S[i]) {
            cur++;
            if(cur>max_len[tmp-'a']) {
                max_len[tmp-'a']=cur;
            }
        } if(tmp != S[i]){
            tmp = S[i];
            cur=1;
            if(cur>max_len[tmp-'a']) {
                max_len[tmp-'a']=cur;
            }
        }
    }
    rep(i,26) {
        ans += max_len[i];
    }
    cout << ans << endl;
}