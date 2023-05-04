#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n+1],s[n+1];
  for(int i=1;i<=n;i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  a[0]=0; s[0]=0;
  for(int i=0;i<n;i++) {
    s[i+1]=s[i]+a[i+1];
  }
  int l,r;
  for(int i=0;i<q;i++) {
    cin >> l >> r;
    //l-r+1 is range
    if(2*(s[r]-s[l-1])>r-l+1) {
      cout << "win" << endl;
    } 
    if(2*(s[r]-s[l-1])<r-l+1) {
      cout << "lose" << endl;
    }
    if(2*(s[r]-s[l-1])==r-l+1) {
      cout << "draw" << endl;
    }
  }
}