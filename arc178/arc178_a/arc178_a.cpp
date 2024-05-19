#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;


int main() {
    int N,M;
    cin >> N >> M;
    vector<int> a(M+1);
    map<int, int> mp;
    rep(i,0,M){
        cin >> a[i];
    }
    rep(i,1,N+1){
        mp[i] = i;
    }

    sort(all(a));
    reverse(all(a));

    rep(i,0,M){
        if(a[i] == 1||a[i]==N) {
            cout << -1 << endl;
            return 0;
        }
        int tmp;
        tmp = mp[a[i]];//a[i]の位置
        mp[a[i]] = mp[a[i]+1];
        mp[a[i]+1] = tmp;
    }
    vector<int> ans(N);
    rep(i,1,N+1){
        ans[mp[i]-1] = i;
    }
    rep(i,0,N){
        cout << ans[i] <<" ";
    }
    
}