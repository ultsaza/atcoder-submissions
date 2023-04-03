/* writer @ult_saza */

#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<pair<int,int>> p(N);
  
  for (int i=0; i<N; i++) {
    int a,b;
    cin >> a >> b;
    swap(a,b);
    p.at(i) = make_pair(a,b);
  }
  
  sort(p.begin(),p.end());
  
  for (int i=0; i<N; i++) {
    int c,d;
    tie(c,d) = p.at(i);
    cout << d << " " << c << endl;
  }
}