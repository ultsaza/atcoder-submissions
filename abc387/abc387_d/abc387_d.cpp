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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,0,h) cin >> s[i];
    int sx,sy,gx,gy;
    rep(i,0,h) rep(j,0,w) {
        if(s[i][j] == 'S') {
            sx = i;
            sy = j;
        }
        if(s[i][j] == 'G') {
            gx = i;
            gy = j;
        }
    }
    vector<vector<bool>> visited(h,vector<bool>(w,false));
    queue<pl> q;
    q.push({sx,sy});
    int ans = -1;
    vector<vector<int>> dist(h,vector<int>(w,INF));
    dist[sx][sy] = 0;
    visited[sx][sy] = true;
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
         
        rep(i,0,4) {
            if (dist[x][y] % 2 == 0 && i % 2 == 0) continue;
            if (dist[x][y] % 2 == 1 && i % 2 == 1) continue;
            if (x+dx[i] < 0 || x+dx[i] >= h || y+dy[i] < 0 || y+dy[i] >= w) continue;
            if (s[x+dx[i]][y+dy[i]] == '#') continue;
            if (visited[x+dx[i]][y+dy[i]]) continue;
            visited[x+dx[i]][y+dy[i]] = true;
            dist[x+dx[i]][y+dy[i]] = dist[x][y] + 1;
            q.push({x+dx[i],y+dy[i]});
            //cout << x+dx[i] << " " << y+dy[i] << endl;
        }
    }
    int tmp = dist[gx][gy];

    dist = vector<vector<int>>(h,vector<int>(w,INF));
    dist[sx][sy] = 0;
    visited = vector<vector<bool>>(h,vector<bool>(w,false));
    visited[sx][sy] = true;
    q.push({sx,sy});    
     while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
         
        rep(i,0,4) {
            if (dist[x][y] % 2 == 0 && i % 2 == 1) continue;
            if (dist[x][y] % 2 == 1 && i % 2 == 0) continue;
            if (x+dx[i] < 0 || x+dx[i] >= h || y+dy[i] < 0 || y+dy[i] >= w) continue;
            if (s[x+dx[i]][y+dy[i]] == '#') continue;
            if (visited[x+dx[i]][y+dy[i]]) continue;
            visited[x+dx[i]][y+dy[i]] = true;
            dist[x+dx[i]][y+dy[i]] = dist[x][y] + 1;
            q.push({x+dx[i],y+dy[i]});
            //cout << x+dx[i] << " " << y+dy[i] << endl;
        }
    }
    
    if (dist[gx][gy] == INF && tmp == INF) cout << -1 << endl;
    else cout << min(dist[gx][gy],tmp) << endl;
    
    
    
}