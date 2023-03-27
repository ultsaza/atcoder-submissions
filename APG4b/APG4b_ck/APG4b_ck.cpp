#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int p=0,m=0;
  
  for(int i=0;i < S.size();i++) {
    if(S.at(i)=='+') {
      p++;
      }
    else if(S.at(i)=='-') {
      m++;
      }
    }
   
  cout << p-m+1 << endl;
}
