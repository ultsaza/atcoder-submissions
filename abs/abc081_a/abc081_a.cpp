#include<iostream>
#include<string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int c=0;
  for(int i=0;i<3;i++) {
    if(s.at(i)=='1'){
      c++ ;
    }
  }
  cout << c << endl;
}

