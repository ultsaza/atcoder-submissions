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

struct Unionfind{
    vector<int> parent,size;
    Unionfind(int n) : parent(n,-1),size(n,1) {} //-1にするのは全fての頂点は初め独立しているから
    int root(int x) {
        if(parent[x]==-1) return x;

        return parent[x]=root(parent[x]);
    }

    bool is_Same(int x,int y) {
        return root(x)==root(y);
    }

    void unite(int x,int y) {
        int rtX = root(x);
        int rtY = root(y);
        if(rtX==rtY) return;
        if(size[rtX]<size[rtY]) swap(rtX,rtY);
        parent[rtY] = rtX;
        size[rtX] += size[rtY];
    }
};
int main() {
    int N,Q; cin >> N >> Q;
    Unionfind uf(N);
    rep(i,Q) {
        int P,A,B; cin >> P >> A >> B;
        if(P==0) uf.unite(A,B);
        if(P==1){
            if(uf.is_Same(A,B)) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }
}