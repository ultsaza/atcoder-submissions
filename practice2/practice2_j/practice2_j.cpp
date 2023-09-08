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


int op (int a,int b) {return max(a,b);}
int e() {return -1;}
int target;
bool f(int v) {return v < target;}

int main() {
    int N,Q; cin >> N >> Q;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    segtree<int,op,e> seg(a);
    rep(i,Q) {
        int t; cin >> t;
        if(t==1) {
            int x,v; cin >> x >> v;
            x--;
            seg.set(x,v);
        }
        if(t==2) {
            int l,r; cin >> l >> r;
            l--;
            cout << seg.prod(l,r) << '\n';
        }
        if(t==3) {
            int p; cin >> p >> target;
            p--;
            cout << seg.max_right<f>(p)+1 << '\n';
        }
    }
}