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
   int q;
   cin >> q;
   queue<int> que;
   while(q--) {
    int t; cin >> t;
    if(t == 1) {
        int x; 
        cin >> x;
        que.push(x);
    } else {
        cout << que.front() << endl;
        que.pop();
    }
   }

}