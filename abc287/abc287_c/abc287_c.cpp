#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const ll LINF = 0x1fffffffffffffff;

//分岐回数が0,1かどうかを調べれば良い bfsの返り値を分岐回数に
pair<int,int> bfs(vector<vector<int>> G) {
    //1-index
    int section=0;

    int n=G.size();
    queue<int> Q;
    Q.push(1);
    vector<bool> visited(n+1, false);
    visited[1]=true;
    int path=0;
    while(!Q.empty()) {
        int seccnt=0;
        int u=Q.front();
        Q.pop();
        for(auto v:G[u]) {
            if(visited[v]==false) {
                Q.push(v);
                visited[v]=true;
                path++;
                seccnt++;
            }
        }
        if(seccnt>1) {
            section++;
        }
    }
    /*bool alltrue=true;
    for(auto v : visited) {
        if(v==visited[0]) continue;
        alltrue = alltrue && v;
    }
    if(!alltrue) return 3;*/
    pair<int,int> p=make_pair(section, path);
    return p;
}
int main(void) {
    int N,M;cin>>N>>M;
    vector<vector<int>> G(N+1);
    rep(i,M) {
        int v,u;cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    //cout << bfs(G).first << " " << bfs(G).second << endl;
    if(bfs(G).first<2 && M+1==N && bfs(G).second==N-1) cout << "Yes";
    else cout << "No";
}