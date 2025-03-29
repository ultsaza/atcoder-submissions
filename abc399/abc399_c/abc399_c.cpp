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

int main(){
	ll N,M;
	cin >> N >> M;

	vector<vector<ll>> G(N);
	rep(i,0,M){
		int a,b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);	
	}

	queue<ll> que;
	vector<bool> visited(N, false);


	ll n_edges = 0;
	rep(k, 0, N) {
		if(visited[k]) continue;
		que.push(k);
		visited[k] = true;
		while(!que.empty()){
			int v = que.front();
			que.pop();
			for(auto i : G[v]){
				if(!visited[i]){
					visited[i] = true;
					n_edges++;
					que.push(i);
				}
			}
		}
	}

	cout << M - n_edges << endl;

}