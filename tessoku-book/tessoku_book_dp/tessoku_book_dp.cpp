#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i < (int)(n); i++)
const ll M=1000000007;

int n,m;
vector<int> a(200009);
vector<int> ans(200009);
int main() {
    cin >> n >> m;
    rep(i,n) ans[i]=m;
    rep(i,m) {
        cin >> a[i];
        ans[a[i]-1]--;
    }
    rep(i,n) cout << ans[i] << '\n';
}