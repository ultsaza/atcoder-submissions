#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define all(v) v.begin(), v.end()
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
const ll LINF = 0x1fffffffffffffff;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<bool> b(3,0);
    int i=0;
    while(1) {
        if(s[i]=='A') b[0]=1;
        if(s[i]=='B') b[1]=1;
        if(s[i]=='C') b[2]=1;
        if(b[0]&b[1]&b[2]) {
            cout << i+1;
            return 0;
        }
        i++;
    }
}