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
    ll n,m;
    cin >> n >> m;
    vvl G(n);
    rep(i,0,m){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
    }
    queue<pl> q;
    vector<bool> visited(n, false);

    q.push({0,0});
    visited[0] = true;
    ll loop_end = -1;
    while(!q.empty()){
        auto [v, d] = q.front();
        q.pop();
        for(auto nv : G[v]){
            if (nv == 0) {
                //cout << "loop_end: " << v+1 << endl;
                loop_end = v;
                q = queue<pl>();
                break;
            }
            if(!visited[nv]){
                visited[nv] = true;
                q.push({nv, d+1});
            }
        }
    }
    if (loop_end == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector<bool> visited2(n, false);
    queue<pl> q2;
    q2.push({0, 0});
    visited2[0] = true;
    while(!q2.empty()){
        auto [v, d] = q2.front();
        q2.pop();
        for(auto nv : G[v]){
            if (nv == loop_end) {
                cout << d + 2 << endl;
                return 0;
            }
            if(!visited2[nv]){
                visited2[nv] = true;
                q2.push({nv, d+1});
            }
        }
    }



}