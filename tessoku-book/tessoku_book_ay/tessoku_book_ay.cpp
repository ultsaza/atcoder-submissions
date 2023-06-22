#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i < (int)(n); i++)
const ll M=1000000007;

int main(){
    int q;
    vector<int> t(100009);
    vector<string> x(100009);
    stack<string> s;
    cin >> q;
    rep(i,q) {
        cin >> t[i];
        if(t[i]==1) cin >> x[i];
    }
    rep(i,q) {
        if(t[i]==1) s.push(x[i]);
        if(t[i]==2) cout << s.top() << '\n';
        if(t[i]==3) s.pop();
    }
}