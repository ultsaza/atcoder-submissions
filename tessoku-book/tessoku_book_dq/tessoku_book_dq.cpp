#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i <= (int)(n); i++)
const ll M=1000000007;

int n,q;
vector<vector<int>> a(509,vector<int> (509));
vector<int> e(509);
int main() {
    cin >> n;
    rep(i,n) {
        e[i]=i;
        rep(j,n) cin >> a[i][j];
    }
    cin >> q;
    rep(i,q) {
        int que,x,y;
        cin >> que >> x >> y;
        if(que==1) {
            swap(e[x],e[y]);
        }
        if(que==2) {
            cout << a[e[x]][y] << '\n';
        }
    }
}