#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;

int main() {
	int n;
	cin >> n;
	vvl G(n);
	vl color(n,-1);
	rep(i,0,n-1){
		int a,b;
		cin >> a >> b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	color[0]=1;
	queue<int> que;
	que.push(0);
	// 二部グラフの色付け
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(auto nv:G[v]){
			if(color[nv]==-1){
				color[nv]=1-color[v];
				que.push(nv);
			}
		}
	}
	set<pl> st;
	rep(i,0,n){
		rep(nv,0,n){
			if (find(G[i].begin(), G[i].end(), nv) != G[i].end()) continue;
			if(color[nv] != color[i]){
				if(i < nv){
					st.insert({i,nv});
				}
			}
		}
	}
	if(st.size() % 2 == 0){
		cout << "Second" << endl;
	} else {
		cout << "First" << endl;
		auto it = st.begin();
		pl p = *it;
		cout << p.first + 1 << " " << p.second + 1 << endl;
		st.erase(it);
	}
	while(1) {	
		int a,b;
		cin >> a >> b;
		if (a == -1 && b == -1) {
			return 0;
		}
		a--;b--;
		st.erase({a,b});
		auto it = st.begin();
		pl p = *it;
		cout << p.first + 1 << " " << p.second + 1 << endl;
		st.erase(it);
	}
}