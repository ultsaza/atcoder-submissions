#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
ll power(ll a,ll b,ll m) {
    ll p=a, ans=1;
    for(int i=0;i<60;i++) {
        ll d=(1LL<<i);
        if((b/d)%2==1) {
            ans = (ans*p)%m;
        }
        p=(p*p)%m;
    }
    return ans;
}
int main(){
    ll a,b;
    cin >> a >> b;
    cout << power(a,b,1000000007);
}