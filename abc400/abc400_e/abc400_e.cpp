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
#define INF 1e18
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;




int main() {
    ll q; cin >> q;
    vl a(q);
    rep(i, 0, q) {
        cin >> a[i];
    }
    
    vl n_factor(1000001, 0);
    rep(i,2,1000001) {
        if (n_factor[i] == 0) {
            for (ll j = i; j < 1000001; j += i) {
                n_factor[j]++;
            }
        }
    }
    // 各クエリaでn_factor=2となるa以下最大の整数を探せばよい
    // クエリをソートしておけば一度10^6まで捜査すればOK?

    vector<pl> query(q);
    rep(i, 0, q) {
        query[i] = {a[i], i};
    }
    vl ans(q);
    
    sort(all(query));
    reverse(all(query));
    // 大きいものから処理
    ll query_index = 0;
    for(ll i = 1000000; i >= 2; i--) {
        if (n_factor[i] == 2) {
            while(query_index < q && query[query_index].first >= i * i) {
                ans[query[query_index].second] = i * i;
                query_index++;
            }
            if(query_index >= q) break; // All queries processed
        }
    }

    rep(i, 0, q) {
        cout << ans[i] << endl;
    }
   
}