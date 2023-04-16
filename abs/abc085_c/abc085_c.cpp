#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;
  int a=-1,b=-1,c=-1;
  for(int x=0;x<=N;x++) {
    for(int y=0;x+y<=N;y++) {
      int z=N-x-y;
      if(10000*x+5000*y+1000*z==Y) {
        a=x, b=y, c=z;
      }
    }
  }
      cout << a <<" "<< b << " "<< c <<endl;
}