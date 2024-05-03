#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;


int main() {
    ll a,b,c;
    cin >> a >>b >> c;
    if(4*a*b< (c-a-b)*(c-a-b) && c-a-b>0) cout << "Yes" << endl;
    else cout << "No" << endl;
}