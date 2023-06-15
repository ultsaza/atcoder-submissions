#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define revrep2(i, s, n) for (int i= (s); i >= (int)(n); i--)
const ll M=1000000007;


int main() {
    int n;ll ans=0;
    cin >> n;
    vector<int> a(n+1);
    rep(i,n) cin >> a[i];
    vector<ll> cnt(101,0);
    rep(i,n) cnt[a[i]]++;
    rep(i,100) ans += (((cnt[i])*(cnt[i]-1)*(cnt[i]-2)) / 6);
    cout << ans;
}