/**#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
using str=string;
bool cyc(str x) {str a="",b="";for(int i=0;i<x.size();i++){a += x[i];b += x[x.size()-i-1];} if(a==b){return true;}else{return false;}}
int main() {
    str s;cin >> s;
    int w=s.size();
    int dp[1009][1009]; // i->j max cycle
    // dp[1][s.size()] is ans
    for(int i=1;i<=w;i++) {
        dp[i][i]=1;
    }
    for(int len=1;len<w;len++) {//len==l-r
        for(int l=1;l<=w-len;l++) {
            int r=len+l;

        }
    }
}**/
#include <iostream>
#include <algorithm>
using namespace std;
 
int N;
int dp[1009][1009];
string S;
 
int main() {
	// 入力
	cin >> N;
	cin >> S;
 
	// 動的計画法（初期状態）
	for (int i = 0; i < N; i++) dp[i][i] = 1;
	for (int i = 0; i < N - 1; i++) {
		if (S[i] == S[i + 1]) dp[i][i + 1] = 2;
		else dp[i][i + 1] = 1;
	}
 
	// 動的計画法（状態遷移）
	for (int LEN = 2; LEN <= N - 1; LEN++) {
		for (int l = 0; l < N - LEN; l++) {
			int r = l + LEN;
 
			if (S[l] == S[r]) { //先頭と末尾を見れば＋２が確定する
				dp[l][r] = max({ dp[l][r - 1], dp[l + 1][r], dp[l + 1][r - 1] + 2 });
			}
			else {
				dp[l][r] = max({ dp[l][r - 1], dp[l + 1][r] });
			}
		}
	}
 
	// 答えを求める
	cout << dp[0][N - 1] << endl;
	return 0;
}