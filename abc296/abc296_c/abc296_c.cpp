#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;

int main() {
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    int i=0;
    rep(j,n) {
        while(i<n && a[i]-a[j]<x) i++;//iはリセットしなくても良い😁
        //jは開始位置　sort済みであることからiを増やすことでxに近づく　
        //xを越えたらjを増やしてみる
        if(i<n && a[i]-a[j]==x) {
            cout << "Yes" << '\n';
            return 0;   
        }
    }
    cout << "No" << '\n';
}

