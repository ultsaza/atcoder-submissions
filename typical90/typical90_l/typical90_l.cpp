#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, r) for (ll i = 0; i < (r); ++i)
#define all(x) (x).begin(), (x).end()

class uf {
    public:
            vector<int> par;

            void init(int sz) {
                par.resize(sz, -1);
            }

            int root(int pos) {
                if(par[pos] == -1) {
                    return pos;
                }
                par[pos] = root(par[pos]);
                return par[pos];
            }
            void unite(int u, int v) {
                u = root(u);
                v = root(v);
                if(u == v) return;
                par[u] = v;
            }
            bool same(int u, int v) {
                if(root(u) == root(v)) {
                    return 1;
                }
                return 0;
            }
};

int h, w, q;
uf UF;

bool used[2009][2009];

void query1(int px, int py) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    rep(i,4) {
        int sx = px + dx[i];
        int sy = py + dy[i];

        if(used[sx][sy] == false) {
            continue;
        }
        int hash1 = (px - 1) * w + (py - 1);
        int hash2 = (sx - 1) * w + (sy - 1);
        UF.unite(hash1, hash2);
    }
    used[px][py] = true;
}

bool query2(int px, int py, int qx, int qy) {
    if(used[px][py] == false || used[qx][qy] == false) {
        return false;
    }

    int hash1 = (px - 1) * w + (py - 1);
    int hash2 = (qx - 1) * w + (qy - 1);

    if(UF.same(hash1, hash2) == true) return true;
    return false;
}

int main() {
    cin >> h >> w >> q;
    UF.init(h * w);

    rep(_, q) {
        int ty; cin >> ty;
        if(ty == 1) {
            int x, y;
            cin >> x >> y;
            query1(x, y);
        }
        if(ty == 2) {
            int xa, xb, ya, yb;
            cin >> xa >> xb >> ya >> yb;
            bool ans = query2(xa, xb, ya, yb);
            if(ans == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}
