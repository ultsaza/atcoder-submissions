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
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;



/*
方向付きの距離のようなものを考えていたが、
トポロジカルソートなるもので実装できるらしい
方向付きの距離が頂点1から遠いやつから読んでいけば良い
*/

/**トポロジカルソートの実装方法**/
// 入次数0の頂点vを探す
// vを配列に追加
// グラフからvとvにつながる辺を削除
vector<int> topological_sort(vector<vector<int>> G) {
    int n=G.size(); //G[i]はi->jを満たすjのリスト
    vector<int> indegtree(n);//入次数って意味らしい
    rep(i,n) for(auto j:G[i]) indegtree[j]++;
    vector<int> res;
    queue<int> Q;
    rep(i,n) if(indegtree[i]==0) Q.push(i);
    while(!Q.empty()) {
        int ver=Q.front(); Q.pop();
        res.push_back(ver);
        for(auto j:G[ver]) {
            indegtree[j]--;//辺の消去に対応
            if(indegtree[j]==0) Q.push(j);
        }
    }
    return res;
}

int main() {
    int N; cin >> N;
    vector<vector<int>> G(N);
    rep(i,N) {
        int c; cin >> c;
        rep(_,c) {//普通にjって書けばいいと思うけど、変数が介入しないことの強調かな
            int v; cin >> v;
            v--;
            G[i].push_back(v);//これ逆でもいけるはず
        }
    }
    queue<int> Q;
    Q.push(0);
    vector<bool> visited(N, false);
    //ここでbfs　頂点1からの経路があるかどうかの判定（孤立した頂点が邪魔なので）
    while(!Q.empty()) {
        int u=Q.front(); Q.pop();
        for(auto v:G[u]) {
            if(visited[v]) continue;
            visited[v]=true;
            Q.push(v);
        }
    }
    vector<int> res=topological_sort(G);
    vector<int> order(N);//トポロジカルソート後の順序
    rep(i,N) order[res[i]]=i;//トポロジカルソートした後の各頂点が何番目か
    vector<int> ans;
    rep(i,N) if(visited[i]) ans.push_back(i);
    //逆順にsort
    sort(all(ans),[&](int a, int b){return order[a]>order[b];});
    rep(i,ans.size()) cout << ans[i]+1 << " ";
}