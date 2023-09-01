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
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;


int H,W;
vector<string> G;//ここでサイズ決めない
bool vis[509][509];
void dfs(int h,int w) {
    vis[h][w]=true;
    rep(dir,4) {
        int nh = h+dx[dir];
        int nw = w+dy[dir];
        if(nh<0||nh>=H||nw<0||nw>=W) continue;
        if(G[nh][nw]=='#')continue;
        if(vis[nh][nw]) continue;

        dfs(nh,nw);
    }
}
int main() {
    cin >> H >> W;
    G.resize(H);
    rep(i,H) cin >> G[i];
    int sh,sw,gh,gw;
    rep(h,H)rep(w,W) {
        if(G[h][w]=='s') sh=h,sw=w;
        if(G[h][w]=='g') gh=h,gw=w;
    }
    rep(h,509)rep(w,509) vis[h][w]=false;
    dfs(sh,sw);
    if(vis[gh][gw])cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
