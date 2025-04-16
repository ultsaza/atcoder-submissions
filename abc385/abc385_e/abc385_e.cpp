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
using mint=modint998244353;
#define INF 1000000009
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

int main() {
    int n;
    cin >> n;
    vvi G(n);
    rep(i,0,n-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int mx = 0;
    rep(i,0,n) {
        vi size_list;
        for(auto j:G[i]) {
            if (G[j].size() == 1) continue;
            size_list.push_back(G[j].size());
        }
        sort(all(size_list));
        reverse(all(size_list));
        
        if(size_list.size() > 0) {
            rep(j,0,size_list.size()) {
                mx = max(mx, (int)(1 + (j + 1) * size_list[j]));
            }
        }
    }
    cout << n-mx << endl;
}