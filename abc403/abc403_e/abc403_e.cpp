#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using ld = long double;
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;


struct Trie {
    vector<map<char,int>> to;
    Trie(): to(1) {}
    int add(const string &s) {
        int v = 0;
        for (char c : s) {
            if(!to[v].count(c)) {
                int nv = to.size(); //最大の頂点番号.
                to.push_back(map<char,int>());
                to[v][c] = nv;
            }
            v = to[v][c];
        }
        return v;
    }
    int ans;
    vector<bool> ng;
    vi ny;
    void init() {
        ans = 0;
        int n = to.size();
        ng.resize(n);
        ny.resize(n);
    }
    void addx(int v) {
        if(ng[v]) return;
        ng[v] = true;
        ans -= ny[v];
        for(auto [c,nv] : to[v]) addx(nv);
    }
    void addy(int v) {
        if(ng[v]) return;
        ans++;
        ny[v]++;
    }
};
int main() {
    int q; cin >> q;
    Trie trie;
    vector<pair<int,int>> query(q);
    rep(i,0,q) {
        int t;
        string s;
        cin >> t >> s;
        int v = trie.add(s);
        query[i] = {t,v};
    }
    trie.init();
    for(auto [t,v] : query) {
        if(t == 1) trie.addx(v);
        else trie.addy(v);
        cout << trie.ans << endl;
    }
}
