#include<iostream>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
const ll M=1000000007;

int main() {
    int  n,x,y,a[100009];
    cin >> n >> x >> y;
    rep(i,n) cin >> a[i];
    int grundy[100009];
    rep2(i,0,100000) {
        bool transit[3]={false,false,false};
        if(i>=x)transit[grundy[i-x]]=true;
        if(i>=y)transit[grundy[i-y]]=true;
        if(transit[0]==false) grundy[i]=0;
        else if(transit[1]==false) grundy[i]=1;
        else grundy[i]=2;
    }
    int XOR_Sum=0;
    rep(i,n) XOR_Sum = (XOR_Sum^grundy[a[i]]);
    if(XOR_Sum!=0) cout << "First";
    else cout << "Second";
}