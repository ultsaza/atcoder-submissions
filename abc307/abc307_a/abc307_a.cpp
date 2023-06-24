#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i < (int)(n); i++)
const ll M=1000000007;

int main(){
    ll n;
    vector<ll> a(700009);
    cin >> n;
    rep(i,7*n) cin >> a[i];
    rep(i,n) {
        ll ans=0;
        rep(j,7) {
            ans += a[7*i+j];
        }
        cout << ans << " ";
    }
}