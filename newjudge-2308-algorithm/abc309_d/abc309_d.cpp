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

//sを始点としたBFS　visitedの判定をdistが-1か否かで判定
int bfs(vector<vector<int>> E,int s) {
    int n = E.size();
    vector<int> dist(n,-1);
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        //Q.front() につながる頂点について調べる
        for(int v : E[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    return *max_element(all(dist)); //max_elementはイテレータを返すので＊をつけてdistの最大値を返す
}
int main(void) {
    int N_1, N_2,M; cin >> N_1 >> N_2 >> M;
    vector<vector<int>> G(N_1+N_2);
    rep(i,M) {//0-indexed
        int a,b; cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    cout << bfs(G,0)+bfs(G,N_1+N_2-1) +1;
}