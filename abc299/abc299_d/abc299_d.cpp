#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int f=1,e=N;
  int s;
  while(1) {
    cout << "? "<<(f+e)/2<<endl;
    cin >> s;
    if(s==0) {
      f=(f+e)/2;
    } else {
      e=(f+e)/2;
    }
    if(e-f==1) {
      cout << "! "<<f<<endl;
      break;
    }
  }
}
