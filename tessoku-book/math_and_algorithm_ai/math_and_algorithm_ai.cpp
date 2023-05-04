#include<iostream>
using namespace std;

int main() {
  int n,q;
  cin >> n >> q;
  int a[n+1];
  a[0]=0;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
  }
  for(int i=1;i<n;i++) {
    a[i+1]=a[i+1]+a[i];
  }
  for(int i=0;i<q;i++) {
    int l,r;
    cin >> l >> r;
    cout <<a[r]-a[l-1]<< endl;
  }
}