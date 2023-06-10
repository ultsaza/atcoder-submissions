#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const ll M=1000000007;//(10^9 + 7)

// C[H+W-2,H-1] mod M is ans. (H+W-2)!/(H-1)!(W-1)!
ll H,W; ll a=1,b=1; 
int main() {
    cin >> H >> W;
    rep(i,H+W-2) {
        a = ((i+1)*a)%M;
    }
    rep(i,H-1) {
        b = ((i+1)*b)%M;
    }
    rep(i,W-1) {
        b = ((i+1)*b)%M;
    }
    cout << (a*pow_mod(b,M-2,M))%M << '\n';
}