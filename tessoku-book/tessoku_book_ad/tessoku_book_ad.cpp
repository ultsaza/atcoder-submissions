#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
const ll M=1000000007;
// a の　b 乗　mod m
ll Div(ll a,ll b,ll m){
    return (a*pow_mod(b,m-2,m))%m;
}
int main(){
    ll n,r;
    cin >> n >> r;
    ll a=1;
    for(int i=1;i<=n;i++){
        a = (a*i)%M;
    }
    ll b=1;
    for(int i=1;i<=r;i++) b=(b*i)%M;
    for(int i=1;i<=n-r;i++) b=(b*i)%M;
    cout << Div(a,b,M) << '\n';
}