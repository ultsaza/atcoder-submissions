#include<iostream>
using namespace std;

int main() {
  int a,b;
  cin>>a>>b;
  int k=0;
  while(a*k-(k-1)<b) {
    k++;
  }
  cout << k << endl;
}