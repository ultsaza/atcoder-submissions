#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }
//#define _GLIBCXX_DEBUG


int main() {
    string s,t;
    cin>>s>>t;
    s.push_back('#');
    t.push_back('#');
    ll ans=0;
    rep(i,0,s.size()) {
        if(s[i]!=t[i]) {
            ans=i+1;
            break;
        }
    }
    cout<<ans<<endl;
}