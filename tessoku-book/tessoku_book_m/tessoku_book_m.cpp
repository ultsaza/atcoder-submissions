#include<iostream>
using namespace std;

int n,k;
int a[100009],r[100009];

int main() {
  cin >> n >> k;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
  }
  for(int i=1;i<=n;i++) {
    if(i==1) {
      r[i]=1;
    } else {
      r[i]=r[i-1];
    }
 	 while(r[i]<n && a[r[i]+1]-a[i]<=k) {
    	r[i]++;
	  }
	}
	long long ans=0;
	for(int i=1;i<=n-1;i++) {
  		ans += (r[i]-i);
	}
    		cout << ans <<endl;
}