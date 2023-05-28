#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main() {
  int n;
  int a[3009];
  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
  }
  int ans=0;
  for(int i=1;i<=n;i++) {
    ans += a[i]-1;
  }
  cout << ans;
}