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

int main(void){
	string s;
	cin>>s;
	int n=s.size();
	reverse(all(s));
	rep(i,0,n-1){
		if (s[i]=='A' && s[i+1]=='W'){
			s[i]='C';
			s[i+1]='A';
		}
	}
	reverse(all(s));
	cout<<s<<endl;
}
