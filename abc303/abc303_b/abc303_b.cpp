#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main() {
    int n,m;
    int a[59][59],b[59][59];
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            b[i][j]=0;
            if(i==j) {
                b[i][j]=1;
            }
        }
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<n;j++) {
            b[a[i][j]][a[i][j+1]]=1;
            b[a[i][j+1]][a[i][j]]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(b[i][j]==0) {
                ans++;
            }
        }
    }
    cout << ans/2;
}