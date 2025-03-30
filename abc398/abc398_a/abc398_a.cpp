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
	string s;
	rep(i, 0, n) {
		if (i == n/2 || (i == n/2-1 && n%2 == 0)) {
			s += '=';
		} else {
			s += '-';
		}
	}
	cout << s << endl;
}