#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using ld = long double;
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using mint=modint998244353;

int main() {
    string s;
    cin >> s;
    set<char> st;
    rep(i,0,s.size()) {
        st.insert(s[i]);
    }
    
    rep(i,0,26) {
        if (!st.count('a' + i)) {
            cout << (char)('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
    
    
    

}