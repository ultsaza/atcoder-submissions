#include<iostream>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
const ll M=1000000007;

int main() {
    int n,a[100009],b[100009];
    cin >> n;
    int h,w; cin>> h >> w;
    rep(i,n) cin >> a[i] >> b[i];
    int XOR_sum=(a[1]-1);
    rep2(i,2,n)  XOR_sum = (XOR_sum ^ (a[i]-1));
    rep(i,n)  XOR_sum = (XOR_sum ^ (b[i]-1));
    if(XOR_sum != 0) cout << "First" << '\n';
    if(XOR_sum == 0) cout <<"Second" << '\n';
}