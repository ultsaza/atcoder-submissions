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
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;

int main() {
   string s; cin >>s;
   vector<string> T={
"tourist",
"ksun48",
"Benq",
"Um_nik",
"apiad",
"Stonefeang",
"ecnerwala",
"mnbvmar",
"newbiedmy",
"semiexp"};
    vector<int> v={3858,3679
,3658,
3648,
3638,
3630,
3613,
3555,
3516,
3481};

rep(i,10) {
    if(s==T[i]) {
        cout << v[i];
    }
}
}