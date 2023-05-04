#include<iostream>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  bool div=0;
  for(int i=a;i<=b;i++) {
    if(100%i==0) {
      div=1;
    }
  }
  if(div) cout << "Yes";
  else cout << "No";
}