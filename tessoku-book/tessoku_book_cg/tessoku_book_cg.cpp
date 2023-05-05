#include<iostream>
using namespace std;

int main() {
  int n,x[100009],y[100009],q;
  int a[100009],b[100009],c[100009],d[100009];
  cin >> n;
  int p[1509][1509];
  int z[1509][1509];
  for(int i=1;i<=n;i++) {
    cin >> x[i] >> y[i];
    p[x[i]][y[i]]++;
  }
  cin >> q;
  for(int i=1;i<=q;i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  for(int i=1;i<=1500;i++) {
    for(int j=1;j<=1500;j++) {
      z[i][j]=z[i][j-1]+p[i][j];
    }
  }
  for(int j=1;j<=1500;j++) {
    for(int i=1;i<=1500;i++) {
      z[i][j]=z[i-1][j]+z[i][j];
    }
  }
  for(int i=1;i<=q;i++) {
    cout << z[c[i]][d[i]] + z[a[i]-1][b[i]-1]
      - z[a[i]-1][d[i]] -z[c[i]][b[i]-1]
      << endl;
  }
}