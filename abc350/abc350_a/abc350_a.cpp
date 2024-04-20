#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;

int main() {
    string S;
    cin >> S;
    string t="";
    rep(i,3,6) t += S[i];
    int n = stoi(t);
    if(n>=1 && n <=349 && n!=316) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}