#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

ll n,k;
ll a[100009];

bool cheak(ll x) {
    ll sum=0;
    for(int i=1;i<=n;i++) {
        sum += x/a[i];
    }
        if(sum>=k) {
            return true;
        } else {
            return false;
        }
}

int main() {
    cin >> n >> k;
    for (int i=1;i<=n; i++)
    {
        cin >> a[i];
    }
    ll left=1, right = 1000000000;
    while (left<right)
    {
        ll mid=(left+right)/2;
        bool ans = cheak(mid);
        if (ans==false)
        {
            left = mid +1;
        }  if(ans==true) {
            right = mid;
        }
    }
    cout << left << endl;
}