#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;

int N;
vector<vector<int>> G;
vector<int>ans;

void dfs(int crr,int pre){
  ans.push_back(crr);
  for(int nxt:G[crr])if(nxt!=pre){
    dfs(nxt,crr);
    ans.push_back(crr);
  }
}


int main() {
    cin >> N;
    G.resize(N);
    rep(i,0,N-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,0,N) {
        sort(all(G[i]));
    }
    dfs(0, -1);
  
  
  for(auto u: ans) {
    cout << ++u << ' ';
  }

}


