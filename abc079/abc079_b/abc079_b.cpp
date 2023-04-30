#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  vector<long long> l(n+1);
  l[0]=2;l[1]=1;
  for(int i=0;i<n-1;i++) {
    l[i+2]=l[i]+l[i+1];
  }
  cout << l[n] << endl;
}