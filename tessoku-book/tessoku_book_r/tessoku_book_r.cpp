#include<iostream>
using namespace std;

int main() {
    int n,s,a[69];
    bool dp[69][10009];//dp[i][j]はiまでのカードでjを構成できるかを表す

    cin >> n >> s;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    dp[0][0]=true;
    for (int i = 1; i <=s; i++)
    {
        dp[0][i]=false;
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            //a[i]を足せない時の操作
            if(j<a[i]){
                if (dp[i-1][j]==true)
                {
                    dp[i][j]=true;
                }
                else {
                    dp[i][j]=false;
                }
            }
            //足せる時の操作
            if (j>=a[i])
            {
                if (dp[i-1][j]==true || dp[i-1][j-a[i]]==true)
                {
                    dp[i][j]=true;
                }
                else {
                    dp[i][j]=false;                
                }
                
            }
            
        }
        
    }
    if(dp[n][s]==true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
}