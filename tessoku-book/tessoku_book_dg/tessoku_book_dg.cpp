#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
const ll M=1000000007;

int main() {
    int  n,x,y;
    string a[100009];
    cin >> n >> x >> y;
    rep(i,n) cin >> a[i];
    int grundy[100009];
    rep(i,n) {
        reverse(a[i].begin(),a[i].end());
        if((a[i])[0]=='0' || (a[i])[0]=='1' || (a[i])[0]=='5' || (a[i])[0]=='6') grundy[i]=0;
        if((a[i])[0]=='2' || (a[i])[0]=='3' || (a[i])[0]=='7' || (a[i])[0]=='8') grundy[i]=1;
        if((a[i])[0]=='4' || (a[i])[0]=='9') grundy[i]=2; 
    }
    int XOR_Sum=0;
    rep(i,n) XOR_Sum = (XOR_Sum^grundy[i]);
    if(XOR_Sum!=0) cout << "First";
    else cout << "Second";
}