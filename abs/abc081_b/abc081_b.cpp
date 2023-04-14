#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for(int i=0;i<N;i++) {
    cin >> v.at(i);
  }
  int count=0;
  while(true) {
    bool eodd = false;
    for(int i=0;i<N;i++) {
      if(v.at(i)%2 !=0) {
        eodd = true;
      }
    }
    if(eodd) {
      break;
    }
    for(int i=0;i<N;i++) {
      v.at(i) /= 2;
    }
    count++;
  }
  cout << count << endl;
}
      