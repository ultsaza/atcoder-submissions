#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i < (int)(n); i++)
const ll M=1000000007;

int n,k;
vector<int> a(309); vector<int> b(309);
int GET(int x,int y) {
    int c=0;
    rep(i,n) {
        if(x<=a[i] && x+k>=a[i] && y<=b[i] && y+k>=b[i]) c++;
    }
    return c;
}
int main() {
   cin >> n >> k;
   rep(i,n) cin >> a[i] >> b[i];
   int ans=0;
   rep(m,100) {
    rep(l,100) {
        ans = max(ans,GET(m+1,l+1));
    }
   }
   cout << ans << '\n';
}