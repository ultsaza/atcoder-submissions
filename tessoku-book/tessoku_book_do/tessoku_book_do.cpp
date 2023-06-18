#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i < (int)(n); i++)
const ll M=1000000007;

ll n;
vector<ll> a(100009);
vector<ll> b(100009);
ll maximate(int x,int y) {
    ll out=0;
    rep(i,n) {
    ll s=a[i],t=b[i];
    if(x==0) s=-a[i];
    if(y==0) t=-b[i]; 
    if(s+t>=0) out += (s+t);
    }
    return out;
}
int main() {
    cin >> n;
    rep(i,n) cin >> a[i] >> b[i];
    ll c1=maximate(0,0);
    ll c2=maximate(0,1);
    ll c3=maximate(1,0);
    ll c4=maximate(1,1);
    cout << max({c1,c2,c3,c4});
}