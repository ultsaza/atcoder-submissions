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


int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    set<char> set0={ 'H' , 'D' , 'C' , 'S' };
    set<char> set1={ 'A' , '2' , '3' , '4' , '5', '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K' };
    rep(i,n) {
        if(set0.find(s[i][0])==set0.end() || set1.find(s[i][1])==set1.end()) {
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i,n-1) rep(j,i+1,n) {
        if(s[i]==s[j]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}