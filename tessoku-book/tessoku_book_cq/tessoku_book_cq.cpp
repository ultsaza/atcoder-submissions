#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n,s,a[69];
    bool dp[69][10009];
    cin >> n >> s;
    dp[0][0]=1;
    for (int i = 1; i <=s; i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for (int i = 1; i <=n; i++){
        for(int j=0;j<=s;j++) {
            if (j < a[i])
            {
             if (dp[i-1][j]==1)
             {
                dp[i][j]=1;
             }
             else {
                dp[i][j]=0;
             }
            }
            if (j>=a[i])
            {
                if (dp[i-1][j]==1 || dp[i-1][j-a[i]]==1)
                {
                    dp[i][j]=1;
                } else {
                    dp[i][j]=0;
                }
                
            }
            
        }
    }
    if(dp[n][s]==0) {
        cout << -1 << endl;
    } else {
   vector<int> Answer;
   int Place = s;
	for (int i = n; i >= 1; i--) {
		if (dp[i - 1][Place] == true) {
			Place = Place - 0; // カード i を選ばない
		}
		else {
			Place = Place - a[i]; // カード i を選ぶ
			Answer.push_back(i);
		}
	}
	reverse(Answer.begin(), Answer.end());
 
	// 出力
	cout << Answer.size() << endl;
	for (int i = 0; i < (int)Answer.size(); i++) {
		if (i >= 1) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
    }
}