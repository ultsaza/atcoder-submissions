#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()

bool func(string &S) {
    int score = 0;
    for(char c: S) {
        if(c == '(') {
            score++;
        } else {
            score--;
        }

        if(score < 0) {
            return 0;
        }
    }
    if(score!=0) {
        return 0;
    }
    return 1;
}
int main() {
    int n;
    cin >> n;
    if(n % 2 != 0) return 0;
    rep(i, 0, (1LL << n)) {
        string s = "";
        int j = i;
        rep(_, 0, n) {
            if (j % 2 == 0) {
                s = "(" + s;
            } else{
                s =+ ")" + s;
            }
            j /= 2;
        }
        if (func(s)) {
            cout << s << endl;
        }
    }
}