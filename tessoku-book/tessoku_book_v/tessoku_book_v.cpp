#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n,a[100009],b[100009],dp[100009];
    cin >> n;
    for(int i=1;i<=n-1;i++) {
        cin >> a[i];
        dp[i+1]=-100000000;
    }
    for(int i=1;i<=n-1;i++) {
        cin >> b[i];
    }
    dp[1]=0;
    for(int i=1;i<=n-1;i++) {
        dp[a[i]]=max(dp[a[i]],dp[i]+100);
        dp[b[i]]=max(dp[b[i]],dp[i]+150);
    }
    cout << dp[n] << endl;
 }