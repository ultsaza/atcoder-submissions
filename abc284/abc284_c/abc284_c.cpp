#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
const ll M=1000000007;

int n,m;
int main() {
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    bool seen[n+9];
    rep(i,n) seen[i]=false;
    queue<int> todo;
    int ans=0;
    // sは調べる起点,s起点のグラフが連結成分の一つと確定したら，　まだ連結成分の判定をしてないグラフの頂点の一つをsとする。
    //seen[u]==true　は連結成分の判定が終わったことを表す。
    rep(i,n) {
        if(seen[i]==false) {
            todo.push(i);
            seen[i]=true;
            while(!todo.empty()) {
                int v = todo.front();
                todo.pop();
                for(int u: g[v]) {
                    if(seen[u] == false) {
                        seen[u] = true;
                        todo.push(u);
                    }
                }
             }
            ans++;
        }
    }
    cout << ans;
}