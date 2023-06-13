#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define revrep2(i, s, n) for (int i= (s); i >= (int)(n); i--)
const ll M=1000000007;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> tmp;
    vector<int> l(n+1);
    vector<int> r(n+1);
    rep(i,n) {
        cin >> l[i] >> r[i];
        tmp.push_back(make_pair(r[i],l[i]));
    }
    sort(tmp.begin(),tmp.end());
    rep(i,n) {
        r[i]=tmp[i-1].first;
        l[i]=tmp[i-1].second;
    }
    int cur=0,ans=0;
    rep(i,n) {
        if(cur<=l[i]) {
            cur=r[i];
            ans++;
        }
    }
    cout << ans << '\n';
}