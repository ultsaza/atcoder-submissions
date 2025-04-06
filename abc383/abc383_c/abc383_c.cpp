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



int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    int h,w,d; cin >> h >> w >> d;
    vector<string> s(h);
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    rep(i,0,h) cin >> s[i];

    int ans = 0;
    queue<tuple<int,int,int>> q;
    rep(i,0,h) rep(j,0,w) {
    if (s[i][j] == 'H') {
            q.push({i,j,0});
            visited[i][j] = true;
            ans++;
        }
    }

   
   while(!q.empty()) {
    auto [x,y,dist] = q.front();
    q.pop();
    rep(i,0,4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (s[nx][ny] != '#' && !visited[nx][ny] && dist < d) {
            visited[nx][ny] = true;
            q.push({nx,ny,dist+1});
            ans++;
        }
    }
   }
    cout << ans << endl;
}