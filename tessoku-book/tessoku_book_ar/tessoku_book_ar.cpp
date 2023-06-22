#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i <= (int)(n); i++)
const ll M=1000000007;

int n,q,state=1; vector<int> E(200009);
int main() {
    cin>>n>>q; rep2(i,1,n) E[i]=i;
    rep(i,q) {
        int type,x,y;cin >> type;
        if(type==1) {
            cin >> x >> y;
            if(state==1) E[x]=y;
            if(state==2) E[n-x+1]=y;
        }
        if(type==2) {
            if(state==1) state =2;
            else state=1;
        }
        if(type==3) {
            cin >> x;
            if(state==1) cout << E[x]<<'\n';
            if(state==2) cout << E[n+1-x] << '\n';
        }
    }
}