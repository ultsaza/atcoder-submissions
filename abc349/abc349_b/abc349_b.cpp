#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;



int main() {
    int c[26];
    rep(i,0,26) c[i] = 0;
    string S;
    cin >> S;
    rep(i,0,S.size()) c[S[i]-'a']++;
    rep(i,1,S.size()+1) {
        int tmp = 0;
        rep(j,0,26) {
            if(c[j]==i) {
                tmp++;
            }
        }
        if (!(tmp==0||tmp==2 )) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}