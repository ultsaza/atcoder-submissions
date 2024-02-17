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
const ll LINF = 0x1ffffffffffffff;


int main() {
    int h,w,n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(h);
    rep(h) cin >> s[i];
    bool ans[h][w];
    rep(i,h)rep(j,w){ans[i][j] = 0;}
    rep(i,h)rep(j,w) {//(i,j)は最初の位置
        bool flag = 1;
        int x = i, y = j;
        if (x < 0 || x >= h || y < 0 || y >= w || s[x][y] == '#') flag = 0;
        rep(k,n) {
            if(!flag) break;
            if (t[k] == 'U') x--;
            if (t[k] == 'D') x++;
            if (t[k] == 'L') y--;
            if (t[k] == 'R') y++;
            if (x < 0 || x >= h || y < 0 || y >= w || s[x][y] == '#') break;
            if (k == n-1) {
                ans[x][y] = 1;
            }
        }
    }
    int a=0;
    rep(i,h)rep(j,w) {
        if (ans[i][j]) a++;
    }
    cout << a << endl;
}