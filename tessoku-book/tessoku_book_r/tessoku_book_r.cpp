#include<bits/stdc++.h>
using namespace std;

int N,S,A[69];
bool dp[69][100009];

int main() {
  cin >> N >> S;
  for(int i=1;i<=N;i++) {
    cin >> A[i];
  }
  dp[0][0]=1;
  for(int i=1;i<=S;i++) dp[0][i]=0;
  
  
  for(int i=1;i<=N;i++) {
    for(int j=0;j<=S;j++) {
      if(j<A[i]) dp[i][j] = dp[i-1][j];
      else {
        dp[i][j] = dp[i-1][j-A[i]] | dp[i-1][j];
      }
    }
  }
  
  if(dp[N][S]) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}