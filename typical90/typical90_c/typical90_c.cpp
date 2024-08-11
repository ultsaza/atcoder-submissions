#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()

vector<int> dfs(const vector<vector<int>> &G, int s) {
    int N = G.size();
    vector<int> d(N, -1);
    d[s] = 0;

    stack<int> st({s}); //スタックにvectorを入れられるらしいですね

    while(!st.empty()) {
        int v = st.top();
        st.pop();
        for (auto nv : G[v]) {
            if(d[nv] == -1) {
                st.push(nv);
                d[nv] = d[v] + 1;
            }
        }
    }
    return d;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    rep(i, 0, N-1) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    
    }
    auto dist1 = dfs(G, 0);
    int m = -1;
    int mv = -1;
    rep(v, 0, N) {
        if(m < dist1[v]) {
            mv = v;
            m = dist1[mv];
        }
    }
    auto dist2 = dfs(G, mv);

    cout << *max_element(all(dist2)) + 1;

}
