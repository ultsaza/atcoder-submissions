#include<iostream>
using namespace std;

int main() {
  int h,w,n;
  int a[100009],b[100009],c[100009],d[100009];
  int x[1509][1509],z[1509][1509];
  cin >> h >> w >> n;
  for(int t=1;t<=n;t++) {
    cin >> a[t] >> b[t] >> c[t] >> d[t];
  }
  for(int t=1;t<=n;t++) {
    x[a[t]][b[t]] ++;
    x[a[t]][d[t]+1] --;
    x[c[t]+1][b[t]] --;
    x[c[t]+1][d[t]+1] ++;
  }
  for(int i=1;i<=h;i++) {
    for(int j=1;j<=w;j++) {
      z[i][j]=z[i][j-1]+x[i][j];
    }
  }
  for(int j=1;j<=w;j++) {
    for(int i=1;i<=h;i++) {
      z[i][j]=z[i][j]+z[i-1][j];
    }
  }
  for(int i=1;i<=h;i++) {
    for(int j=1;j<=w;j++) {
      if(j>1) {
        cout << " ";
      }
      cout << z[i][j];
    }
    cout << endl;
  }
}