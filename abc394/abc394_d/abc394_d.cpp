#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vld = vector<ld>;
bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }
bool chmax(auto& a, auto b) { return a < b ? a = b, 1 : 0; }
//#define _GLIBCXX_DEBUG

int main(){
	string s;
	cin >> s;
	ll n = s.size();
	stack<char> st;

	rep(i, 0, n) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '<') {
			st.push(s[i]);
			//cout << "test: " << i << endl;
		} else {
			if (st.empty() || (
				(s[i] == ')' && st.top() != '(') ||
				(s[i] == ']' && st.top() != '[') ||
				(s[i] == '>' && st.top() != '<') 
			)
			) {
				cout << "No" << endl;
				return 0;
			} else {
				st.pop();
			}
		}
	}
	if (st.empty()) cout  << "Yes" << endl;
	else cout << "No" << endl;
}
