#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[109][19];
int dp[109][1029];
int main() {
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<=m;i++) {
        for(int j=0;j<(1<<n);j++) {
            dp[i][j]=1000000;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=m;i++) {
        for(int j=0;j<(1<<n);j++) {
            int al[19];
            for(int k=1;k<=n;k++) {
                if((j/(1<<(k-1)))%2 == 0) {
                    al[k]=0;
                } else {
                    al[k]=1;
                }
            }
            int v=0;
            for(int k=1;k<=n;k++) {
                if(al[k]==1 || a[i][k]==1){
                    v += (1<<(k-1));
                }
            }
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            dp[i][v]=min(dp[i][v],dp[i-1][j]+1);
    }
}
    if(dp[m][(1<<n)-1]==1000000) {
        cout << -1 << endl;
    } else {
        cout << dp[m][(1<<n)-1] << endl;
    }
}