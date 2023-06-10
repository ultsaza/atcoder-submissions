#include<iostream>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
const ll M=1000000007;

int main() {
    int n,a[100009];
    cin >> n;
    rep(i,n) cin >> a[i];
    int XOR_sum=a[1];
    rep2(i,2,n) {
        XOR_sum = (XOR_sum ^ a[i]);
    }
    if(XOR_sum != 0) cout << "First" << '\n';
    if(XOR_sum == 0) cout <<"Second" << '\n';
}