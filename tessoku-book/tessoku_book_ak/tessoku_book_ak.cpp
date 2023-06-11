#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
const ll M=1000000007;

int main() {
    ll n,m,b,a[200009],c[200009];
    cin >> n >> m >> b;
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> c[i];
    ll suma=0,sumc=0,sumb=0;
    rep(i,n) suma += a[i];
    suma *= m;
    rep(i,m) sumc += c[i];
    sumc *= n;
    sumb = b*m*n;
    cout << suma+sumb+sumc;
}