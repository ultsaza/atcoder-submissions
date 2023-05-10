#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n,a[100009],b[100009],dp[100009];
    vector<int> ans;
    cin >> n;
    for(int i=2;i<=n;i++) {
        cin >> a[i];
    }
    for(int i=3;i<=n;i++) {
        cin >> b[i];
    }
    dp[1]=0; dp[2]=a[2];
    for(int i=3;i<=n;i++) {
        dp[i]=min(dp[i-1]+a[i],dp[i-2]+b[i]);
    }
    int place=n;
    while (true)
    {
        ans.push_back(place);
        if (place==1)
        {
            break;
        }
        if(dp[place-1]+a[place]==dp[place]) 
        {
            place--;
        } else {
            place-=2;
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " " ;
    }
    
}