#include<iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  for(int x=9;x>=0;x--) {
    int div=(1<<x);
    cout << (n/div)%2;
  }
  cout<<endl;
}