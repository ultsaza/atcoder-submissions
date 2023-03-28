#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> stu(N);
  
  int sum;
  
  for(int i=0;i<N;i++) {
    cin >> stu.at(i);
    sum += stu.at(i);
    }
  
  int M=sum/N;
  
  for(int k=0;k<N;k++) {
    cout << abs(M-stu.at(k)) 
      << endl;
    }
  }