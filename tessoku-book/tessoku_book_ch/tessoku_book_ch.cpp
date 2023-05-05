#include<iostream>
using namespace std;

int main() {
  int n;
  int a[100009],b[100009],c[100009],d[100009];
  int x[1509][1509];
  cin >> n;
  
  for(int i=0;i<=1500;i++) {
    for(int j=0;j<=1500;j++) {
      x[i][j]=0;
    }
  }
  for(int i=1;i<=n;i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    x[a[i]][b[i]] ++;
    x[a[i]][d[i]] --;
    x[c[i]][b[i]] --;
    x[c[i]][d[i]] ++;
  }
  for(int i=0;i<=1500;i++) {
    for(int j=1;j<=1500;j++) {
      x[i][j]=x[i][j-1]+x[i][j];
    }
  }
  for(int i=1;i<=1500;i++) {
    for(int j=0;j<=1500;j++) {
      x[i][j]=x[i][j]+x[i-1][j];
    }
  }
  int A=0;
  for(int i=0;i<=1500;i++) {
    for(int j=0;j<=1500;j++) {
      if(x[i][j] >= 1) A++;
    }
  }
  cout << A << endl;
}