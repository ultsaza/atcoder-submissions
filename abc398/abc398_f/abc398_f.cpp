#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;

int main() {
	string s;
	cin >> s;
	ll n = s.size();
	string rev_s=s;
	reverse(all(rev_s));
	vi arr = z_algorithm(rev_s+s);
	ll max_index = n;
	rep(i, n, 2*n) {
		if (arr[i] == 2*n-i) {
			string ans = s.substr(0,i-n) + rev_s;
			cout << ans;
			return 0;
		}
	}
}