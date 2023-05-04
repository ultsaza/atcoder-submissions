#include<iostream>
using namespace std;

int main () {
  int n,x;
  cin >> n >> x;
  int a[n];
  bool b=0;
  for(int i=0;i<n;i++) {
    cin >> a[i];
    if(a[i]==x) {
      b=1;
    }
  }
  if(b) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
