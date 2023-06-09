#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
ll LCM(ll a,ll b) {
    return (a*b)/gcd(a,b);
}
int main() {
    int a,b;
    cin >> a >> b;
    cout << LCM(a,b);
}