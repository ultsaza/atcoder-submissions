#include<iostream>
using namespace std;

int sumf(int n) {
  int sum = 0;
  while(n > 0) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}

int main() {
  int N,A,B;
  cin >> N >> A >> B;
  int ans = 0;
  for(int i=1;i<=N;i++) {
    if(sumf(i) <= B && sumf(i) >= A) {
      ans += i;
    }
  }
  cout << ans << endl;
}