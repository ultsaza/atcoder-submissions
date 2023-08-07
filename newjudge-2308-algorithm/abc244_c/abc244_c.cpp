#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define all(v) v.begin(), v.end()
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
const ll LINF = 0x1fffffffffffffff;

int main() {
    int N; cin >> N;
    vector<bool> y(2*N+2,0); 
    while(1) {
        int j=1;
        rep(i,1,2*N+2) {
            if(!y[i]){
                cout << i << '\n';
                y[i]=1;
                break;
            }
        }
        int c; cin>>c;
        if(c==0)  return 0;
        y[c]=1;
    }
}