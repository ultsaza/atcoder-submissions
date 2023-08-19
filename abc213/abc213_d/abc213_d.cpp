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

vector<vector<int>> G;
vector<int> ans;

void dfs(int crr,int pre) {
    ans.push_back(crr);//行き止まりに行った時戻る動作に対応させることができる
    //行き止まり前の頂点についたら一個前の頂点の他の隣接頂点に移動する操作に入る
    //その時にans.push_back(crr)で戻る操作を実現できる
    for(auto v : G[crr]) {
        if(v == pre) continue;
        dfs(v,crr);
        ans.push_back(crr);
    }
}

int main() {
    int N; cin >> N;
    G.resize(N+1);//これしてあげないとG[i]に要素追加できない
    rep(i,N-1) {
        int a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,1,N+1) sort(all(G[i]));
    dfs(1,-1);
    rep(i,ans.size()) cout << ans[i] <<" ";
}