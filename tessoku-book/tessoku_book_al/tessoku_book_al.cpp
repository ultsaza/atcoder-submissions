#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
const ll M=1000000007;

int n,m;
int main() {
    int D,N;
    cin >> D >> N;
    vector<int> L(N+1);
    vector<int> R(N+1);
    vector<int> H(N+1);
    rep(i,N) cin >> L[i] >> R[i] >> H[i];
    vector<int> lim(D+1,24);
    rep(i,N) {
        rep2(j,L[i],R[i]) {
            lim[j] = min(lim[j],H[i]);
        }
    }
    int ans=0;
    rep(i,D) {
        ans += lim[i];
    }
    cout << ans << '\n';
}