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
#define INF 1e18 // ! lower than 2^60
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;
#define MOD 1000000000

int main() {
   ll n, k;
   cin >> n >> k;
   string s;
   cin >> s;
   ll count_o = 0;
   rep(i, 0, n) {
    if (s[i] == 'o') count_o++;
   }
   string ans = "";
   if (count_o == k) {
    rep(i,0,n) {
        if (s[i] == '?') { 
            ans += '.';
        } else {
            ans += s[i];
        }
    }
   } else {
    rep(i,0,n) {
        if (s[i] == '?') {
            if (i>0  && i < n -1 && (s[i-1] == 'o' || s[i+1] == 'o')) {
                ans += '.';
            } else {
                ans += '?';
            }
        } else {
            ans += s[i];
        }
   }
   ll count_q = 0;
   // count_qはoに置換できる?の最大の数
   bool flag = true;
   ll idx = 0;
   while(idx < n) {
    if (ans[idx] == '?') {
        // ?が連続して奇数個並んでるならその長さ(n+1)/2をcount_qに加算
        // ?が連続して偶数個並んでるならその長さ/2をcount_qに加算
        ll cnt = 1;
        while(idx + cnt < n && ans[idx + cnt] == '?') {
            cnt++;
        }
        if (cnt % 2 == 1) {
            count_q += (cnt + 1) / 2;
        } else {
            count_q += cnt / 2;
        }
        idx += cnt;
    } else {
        idx++;
    }
   }
   if (count_q == k - count_o) {
    ll idx = 0;
    while(idx < n) {
        // 最大になるような置換
        // ?が連続して奇数個並んでるなら?の列をo.o.o.にする
        // ?が連続して偶数個並んでるなら?の列を変えない
        ll cnt = 0;
        while(idx + cnt < n && ans[idx + cnt] == '?') {
            cnt++;
        }
        if (cnt % 2 == 1) {
            bool f = true;
            rep(i,idx,idx + cnt) {
                if (f) {
                    ans[i] = 'o';
                } else {
                    ans[i] = '.';
                }
                f = !f;
            }
        }
        idx += cnt + 1;
    }
    
   }
   
}
 cout << ans << endl;
}