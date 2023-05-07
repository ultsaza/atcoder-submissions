#include<iostream>
#include<algorithm>
using namespace std;

int n,k,a[1009],b[1009],c[1009],d[1009];
int p[1000009],q[1000009];
bool func=0;

int main() {
  cin >> n >> k;
  for(int x=1;x<=n;x++) cin >> a[x];
  for(int y=1;y<=n;y++) cin >> b[y];
  for(int z=1;z<=n;z++) cin >> c[z];
  for(int w=1;w<=n;w++) cin >> d[w];
  
  for(int x=1;x<=n;x++) {
    for(int y=1;y<=n;y++) {
      p[(x-1)*n+y]=a[x]+b[y];
    }
  }
  for(int z=1;z<=n;z++) {
    for(int w=1;w<=n;w++) {
      q[(z-1)*n+w]=c[z]+d[w];
    }
  }
  sort(q+1,q+(n*n)+1);
  for(int i=1;i<=n*n;i++) {
    int pos1=lower_bound(q+1,q+(n*n)+1,k-p[i])-q;
    if(pos1<=n*n && q[pos1]==k-p[i]) {
      func =1;
    }
  }
  if(func) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}