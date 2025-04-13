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
using mint=modint998244353;
#define INF 1e18 
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


int main() {
    ll n;
    cin >> n;
    stack<ll> st;
    ll len = 0;
    ll now_k = -1;
    while (n--) {
        ll a; cin >> a;
        st.push(a);
        if (now_k == -1) {
            now_k = a;
            len = 1;
        } else if (now_k != a) {
            now_k = a;
            len = 1;
        } else {
            len++;
        }

        if (len == now_k) {
            while (!st.empty() && st.top() == now_k) {
                st.pop();
            }
            if (!st.empty()) {
                now_k = st.top();
                len = 0;
                while (!st.empty() && st.top() == now_k) {
                    st.pop();
                    len++;
                }
                rep(i, 0, len) st.push(now_k);
            }
            else now_k = -1;
        }
        cout << st.size() << endl;

    }     
}