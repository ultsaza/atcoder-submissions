#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define INF 4*10e18
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint=modint998244353;

int main() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<ll>> nex(n+1, vector<ll> (26, -1));
    for (ll i=n-1; i >= 0; i--) {
        rep(c,0,26) {
            if (s[i]==c+'a') {
                nex[i][c]=i;
            } else {
                nex[i][c] = nex[i+1][c];
            }
        }
    }
    string ans = "";
    ll i = 0;
    while(ans.size() < k) {
        rep(c, 0, 26) {
            if (n-nex[i][c]+ans.size()>=k && nex[i][c]!=-1) {
                ans += c + 'a';
                i = nex[i][c];
                i++;
                break;
            }
        }
    }
    cout << ans << endl;

}