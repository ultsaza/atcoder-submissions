#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, r) for (ll i = 0; i < (r); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    string s;
    cin >> s;
    reverse(all(s));
    int cnt = 0;
    rep(i, 3) {
        if(s[i] == '0') {
            cnt++;
            continue;
        }
        break;
    }
    reverse(all(s));
    if(cnt == 3) {
        for(int i = 0; i < s.size() - 4;i++) {
            cout << s[i];
        }
    }
    else {
        for(int i = 0; i < s.size() - cnt;i++) {
            cout << s[i];
        }
    }
}