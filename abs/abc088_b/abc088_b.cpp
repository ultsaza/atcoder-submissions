#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  int ap = 0;
  int bp = 0;
  for(int i=0;i<N;i++) {
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for(int i=0;i<N;i+=2) {
    ap += v.at(i);
  }
  for(int i=1;i<N;i+=2) {
    bp += v.at(i);
  }
  cout << ap - bp << endl;
} 