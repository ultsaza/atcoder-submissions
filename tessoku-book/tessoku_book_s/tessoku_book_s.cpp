#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
int N,W;
ll dp[109][100009]; //dp[i][j]はi個のものをjグラム以下になるようにして得る最大の金額
int w[109],v[109];

int main() {
    cin >> N >> W;
    for(int i=1;i<=N;i++) {
        cin >> w[i] >> v[i];
    }
    for(int i=0;i<=N;i++) {
        dp[0][i]=0;
    }
    for(int i=1;i<=N;i++) {
        for(int j=0;j<=W;j++) {
            if(w[i]>j) {
                dp[i][j]=dp[i-1][j];
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
     ll ansmax=0;
    for(int j=1;j<=W;j++) {
        chmax(ansmax,dp[N][j]);
    }
    cout << ansmax << endl;
}