#include<iostream>
using namespace std;

int main() { 
  int n,k;
  cin >> n >> k;
  int oput=0;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      if(0<k-j-i && k-j-i<=n) {
        oput++;
      }
    }
  }
  cout << oput << endl;
}