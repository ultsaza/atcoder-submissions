#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const ll M=1000000007;

int main() {
    // (int)'A' == 65   
    char p,q;
    cin >> p >> q;
    // d はAからの距離
    int d[7];
    d[0]=0;
    d[1]=3;
    d[2]=4;
    d[3]=8;
    d[4]=9;
    d[5]=14;
    d[6]=23;
    cout << abs(d[(int)p - 65]-d[(int)q -65]);
}