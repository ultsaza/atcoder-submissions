#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const ll M=1000000007;

int main() {
   int N,A,B;
   bool dp[100009];
   cin >> N >> A >> B;
   rep(i,N+1) {
    if(i>=A && dp[i-A]==false) {
        dp[i]=true;
    }
    else if(i>=B && dp[i-B]==false) {
        dp[i]=true;
    }
    else{
        dp[i]=false;
    }
   }
   if(dp[N]== true) {
    cout << "First";
   }else {
    cout << "Second";
   }
}