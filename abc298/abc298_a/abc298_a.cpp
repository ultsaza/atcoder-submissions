#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  string s; cin>>s;
  bool a=false,b=true;
  for(int i=0;i<n;i++) {
    if(s[i]=='o') {
      a = true;
    }
    if(s[i] == 'x') {
      b = false;
    }
  }
  if(a && b) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}