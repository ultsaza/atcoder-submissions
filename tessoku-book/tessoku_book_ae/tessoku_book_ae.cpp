#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const ll M=1000000007;//(10^9 + 7)

int main() {
    ll n;
    cin >> n;
    cout << (n/3)+(n/5)-(n/15);
}