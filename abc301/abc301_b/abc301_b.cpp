#include<iostream>
#include<algorithm>
using namespace std;
int main () {
    int n; cin >> n;
    int a[n];for (int i = 0; i < n; i++) {cin >> a[i];}
    int b[20000];b[0]=a[0]; for(int i=1;i<20000;i++) {b[i]=0;}
    int s=0; int r=0;

    for (int i = 0; i < n-1; i++) {
        s=0;
        while(abs(a[i+1]-a[i])>s) {
            if(a[i+1]>a[i]) {
                b[r]=a[i]+s;
                s++;
                r++;
            }
            if(abs(a[i+1]<a[i])) {
                b[r]=a[i]-s;
                s++;
                r++;
            }
            if(abs(a[i+1]==a[i])) {
               b[i]=a[i];
                r++;
            }
        }
    }
    for(int i=0;i<20000;i++) {
        if(b[i] != 0) {
            cout << b[i] << " ";
        }
    }   
  cout << a[n-1];
}