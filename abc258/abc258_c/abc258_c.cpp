#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using ld = long double;
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint1000000007;

int main() {
    ll n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll y=0;
    while(q--) {
        ll t,x;
        cin >> t >> x;
        if(t==1){
            y+=x;
            y%=n;
        }else if(t==2){
            cout << s[(x-1-y+n)%n] << endl;
        }
    }
}