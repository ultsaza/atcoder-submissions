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
const ll LINF = 0x1fffffffffffffff;

int main() {
    int N; cin >> N;
    vector<int> G(N);
    rep(i,N) {
        cin >> G[i];
        G[i]--;
    }
    vector<bool> visited(N,0);
    vector<int> sub;
    int pos=0;
    int start;
    while(!visited[pos]) {
        sub.push_back(pos);
        visited[pos] = true;
        pos = G[pos];
    }
    //for(auto i : ans) cout << i+1 << " ";
    bool flag = false;
    int m=sub.size();
    vector<int> ans;
    rep(i,m) {
        if(sub[i]==pos)flag = true;
        if(flag) ans.push_back(sub[i]);
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i+1 << " ";
}