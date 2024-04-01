#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const int INF = 0x3fffffff;
const ll LINF = 0x1ffffffffffffff;

int N;
int D;
bool connected(int x_1,int y_1,int x_2,int y_2){
    if((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2)<=D*D){
        return true;
    }
    return false;
}

vector<vector<int>> G;
vector<bool> visited;

void dfs(int v) {
    visited[v] = 1;
    for(auto nv:G[v]) {
        if(visited[nv]) continue;
        dfs(nv);
    }
}

int main() {
    
    cin >> N >> D;
    vector<pair<int,int>> xy(N);
    rep(i,N){
        cin>>xy[i].first>>xy[i].second;
    }
    
    G.resize(N);

    rep(i,N) {
        rep(j,i,N) {
            if(connected(xy[i].first,xy[i].second,xy[j].first,xy[j].second)) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

        visited.resize(N,0);
        dfs(0);
        
        rep(k,N) {
            if(!visited[k]) {
                cout << "No" << endl;
            } else {
              cout << "Yes" << endl;
            }
        }
}