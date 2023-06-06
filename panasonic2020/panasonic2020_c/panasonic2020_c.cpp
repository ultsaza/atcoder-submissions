#include<bits/stdc++.h>
using namespace std;
int main() {
  long long a,b,c; cin >> a >> b >> c;
  if(4*a*b<(c-a-b)*(c-a-b) && c-a-b>=0){
    cout << "Yes";
  }else{
    cout << "No";
  }
}