#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
ll z=1000000007;
int main(){
    int n;
    cin >> n;
    ll fibmod[10000009];
    fibmod[1]=1;
    fibmod[2]=1;
    for(int i=3;i<=n;i++) {
        fibmod[i] = ((fibmod[i-1]%z)+(fibmod[i-2]%z))%z;
    }
    cout << fibmod[n] << '\n';
}