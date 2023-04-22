#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> t(N+1,0);
  vector<int> x(N+1,0);
  vector<int> y(N+1,0);
    
  for(int i=1;i<=N;i++) {
    cin >> t[i] >> x[i] >> y[i];
    }
  bool judge=true;
  int dist,time;
  for(int i=1;i<=N;i++) {
    dist=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
    time=t[i]-t[i-1];
    if(dist > time || (dist + time)%2 != 0 ) {
      judge=false;
    }
  }
  
  if(judge) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}