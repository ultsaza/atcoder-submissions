#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;


int main() {
    ll h,cur = 0;
    cin >> h;

    rep(i,0,200) {
        cur += pow(2,i);
        if( cur > h) {
            cout << i+1 << endl;
            return 0;
        }
    }
}