#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> disc(N);
  for(int i=0;i<N;i++) {
    cin >> disc.at(i);
  }
  sort(disc.begin(), disc.end());
  int rank = 1;
  for(int i=1;i<N;i++) {
    if(disc.at(i)!=disc.at(i-1)) {
      rank++;
    }
  }
  cout << rank << endl;
}