#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int n,a[100009],p[100009],q[100009];
  int d,l[100009],r[100009];
  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
  }
   cin >> d;
  for(int i=1;i<=d;i++) {
    cin >> l[i] >> r[i];
  }
  p[1]=a[1];
  for(int i=2;i<=n;i++) {
    p[i]=max(p[i-1],a[i]);
  }
  q[n]=a[n];
  for(int i=n-1;i>=1;i--) {
    q[i]=max(q[i+1],a[i]);
  }
  for(int i=1;i<=d;i++) {
    cout << max(p[l[i]-1],q[r[i]+1]) << endl;
  }
}