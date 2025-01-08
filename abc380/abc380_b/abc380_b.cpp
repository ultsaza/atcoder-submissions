#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vld = vector<ld>;
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }
//#define _GLIBCXX_DEBUG

int main() {
    string s;
    cin>>s;
    vl a;
    ll n=s.size();
    ll cur=0;
    rep(i,1,n){
        if(s[i]=='-') {
            cur++;
        } else {
            a.emplace_back(cur);
            cur=0;
        }
    }
    for(auto t: a) {
        cout << t << " ";
    }
}