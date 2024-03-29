#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const int INF = 0x3fffffff;
const ll LINF = 0x1ffffffffffffff;



bool nearEqual(string s, string t) {
    int cnt = 0;
    rep(i,s.size()) {
        if(s[i] != t[i]) cnt++;
    }
    if(cnt == 1) return true;
    return false;
}
int main() {
    int n,m;
    cin >>n>>m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> io(n);
    iota(all(io),0);
    bool flag = false;
    do{
        flag = true;
        rep(i,n-1) {
            if(!nearEqual(s[io[i]],s[io[i+1]])){
                flag = false;
            }
        }
        if(flag) {
            cout << "Yes" <<endl;
            return 0;
        }
    }while(next_permutation(all(io)));

    cout << "No" <<endl;
    return 0;
}