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
#define INF 4*10e18
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint = modint1000000007;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i,0,h) cin >> g[i];
    queue<pl> q;
    queue<ll> lv;
    rep(i,0,h) rep(j,0,w) {
        if (g[i][j]=='#') {
            q.push({i,j});
            lv.push(0);
        }
    }
    ll prev = 0;
    set<pl> s;
    while(!q.empty()) {
        auto [i,j] = q.front();
        q.pop();
        ll l = lv.front();
        lv.pop();
        if (l != prev) {
            for (auto [i,j]: s) {
                g[i][j] = '#';
            }
            s.clear();
            prev++;
        }
        rep(d,0,4) {
            if (i+dx[d] < 0 || i+dx[d] >= h || j+dy[d] < 0 || j+dy[d] >= w || 
            g[i+dx[d]][j+dy[d]] == '#') continue;
            bool ok = 1;
            rep(e,0,4) {
                if (dx[d]+dx[e]==0 && dy[d]+dy[e]==0) continue;
                if (i+dx[d]+dx[e] < 0 || i+dx[d]+dx[e] >= h || j+dy[d]+dy[e] < 0 || j+dy[d]+dy[e] >= w) continue;
                if (g[i+dx[d]+dx[e]][j+dy[d]+dy[e]] == '#') ok = 0;
                }
            if (ok) {
                q.push({i+dx[d], j+dy[d]});
                s.insert({i+dx[d], j+dy[d]});
                lv.push(l+1);
            }
        }
    }
    ll ans = 0;
    rep(i,0,h) rep(j,0,w) {
        if (g[i][j]=='#') ans++;
    }
    cout << ans << endl;   
}
  