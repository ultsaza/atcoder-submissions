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
    
    int N;
    cin >> N;
    vector<string> p(N); 
    ll T=0;
    rep(i,0,N) {
        int c;
        string s;
        cin >> s >> c;
        T += c;
        p[i] = s;
    }
    sort(all(p));
    cout << p[T%N] << endl;


}