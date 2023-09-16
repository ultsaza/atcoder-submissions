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

bool palindrome(const string& s){
    return equal(s.begin(), s.end(), s.rbegin());
}
int main() {
    //1+2+...+100 < 100*100
    string S;
    cin >> S;
    int ans=1;
    rep(i,2,S.size()+1) {
        for(int j=0;j+i<=S.size();j++) {
            string s = S.substr(j,i);
            if(palindrome(s)) ans = i;
        }
    }
    cout << ans;
}