#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const ll M=1000000007;

int main() {
   int N,K,a[109];
   bool dp[100009];
   cin >> N >> K;
   rep(i,K){
    cin >> a[i];
   }
   rep(i,N+1) {
    dp[i]=false;
   }
   rep(i,N+1) {
    rep(j,K) {
     if(i>=a[j] && dp[i-a[j]]==false) {
            dp[i]=true;
        }
    } 
   }
   if(dp[N]== true) {
    cout << "First";
   }else {
    cout << "Second";
   }
}