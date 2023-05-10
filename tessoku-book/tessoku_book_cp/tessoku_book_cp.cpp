#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
   int n,h[100009],dp[100009];
   cin >> n;
   for(int i=1;i<=n;i++) {
    cin >> h[i];
   }
   dp[1]=0;
   dp[2]=abs(h[1]-h[2]);
   for(int i=3;i<=n;i++) {
    dp[i]=min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i-2]-h[i]));
   }
   int place=n;
   vector<int> P;
   while (1)
   {
    P.push_back(place);
    if(place==1) {
        break;
    }
    if(dp[place-1]+abs(h[place-1]-h[place])==dp[place]) {
        place--;
    } else {
        place--;
        place--;
    }
   }
   reverse(P.begin(),P.end());
   cout << P.size() << endl;
   for(int i=0;i<P.size();i++) {
    cout << P[i] << " ";
   }
}