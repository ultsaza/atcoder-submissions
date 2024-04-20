#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;



int main() {
    string S,T;
    cin >> S >> T;
    transform(all(T), T.begin(), ::tolower);
    if(T[T.size()-1] == 'x') {
        int cnt = 0;
        rep(i,0,S.size()) {
            if(S[i] == T[cnt]) {
                cnt++;
            }
            if(cnt == 2) {
                break;
            }
        }
        if(cnt == 2) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        int cnt =0 ;
        rep(i,0,S.size()) {
            if(S[i] == T[cnt]) {
                cnt++;
            }
            if(cnt == 3) {
                break;
            }
        }
        if(cnt == 3) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}