#include<iostream>
using namespace std;
float n,l=0,r=100;
float f(float x) {
  return x*x*x+x;
}

int main() {
  cin >> n;
  float mid;
  for(int i=0;i<50;i++) {
    mid=(l+r)/2;
    if(f(mid)<n) {
      l=mid;
    } else {
      r=mid;
    }
  }
  cout << mid <<endl;
}