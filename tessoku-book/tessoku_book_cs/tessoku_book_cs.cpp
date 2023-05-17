#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s,t;
int dp[2009][2009];
int main() {
    cin >> s >> t;
    dp[0][0]=0;
    for(int i=0;i<=s.size();i++) {
        for(int j=0;j<=t.size();j++) {
            if(i*j>0 && s[i-1]==t[j-1]) {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1]+1,dp[i-1][j]+1));
            }
            else if(i*j>0) {
                dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i][j-1]+1,dp[i-1][j]+1));
            }
            else if(i>0) {
                dp[i][j]=dp[i-1][j]+1;
            }
            else if(j>0) {
                dp[i][j]=dp[i][j-1]+1;
            }
        }
    }
    cout << dp[s.size()][t.size()] << endl;
}