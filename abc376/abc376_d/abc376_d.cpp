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
    int n,m;
    cin >> n >> m;;
    vvi G(n);
    rep(i,0,m){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
    }

    queue<int> que;
    que.push(0);
    vector<int> dist(n,-1);
    dist[0]=0;
    while(!que.empty()){
        int v=que.front();
        que.pop();
        
        for(auto nv:G[v]){
            if (nv == 0) {
                cout << dist[v]+1 << endl;
                return 0;
            }
            if(dist[nv] != -1) continue;
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    }
    cout << -1 << endl;
}