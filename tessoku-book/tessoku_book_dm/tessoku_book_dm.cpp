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
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i,n) {
        cin >> a[i];
        a[i] %= 100;
    }
    vector<int> cnt(100,0);
    rep(i,n) cnt[a[i]]++;
    ll ans=0;
    rep(i,49) ans += cnt[i]*cnt[100-i];
    ans += cnt[0]*(cnt[0]-1)/2;
    ans += cnt[50]*(cnt[50]-1)/2;
    cout << ans;
}