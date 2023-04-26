#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin>>N>>S;
  int i=0;
  bool a=1,b=1;
  while(a) {
    if(S[i]=='|') {
      a=0;
      }
    if(S[i]=='*') {
      a=0;
      b=0;
      cout << "out" << endl;
      }
    i++;
    }
  while(b) {
    if(S[i]=='|') {
      cout <<"out"<<endl;
      b=0;
      }
    if(S[i]=='*') {
      cout << "in" << endl;
      b=0;
      }
    i++;
    }
  }
    