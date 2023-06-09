#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    ll N,A[100009];char T[100009];
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> T[i] >> A[i];
    }
    ll ans=0;
    for(int i=1;i<=N;i++) {
        if(T[i]=='+' ){
            ans += A[i];
        }
        if(T[i]=='-'){
            ans -= A[i];
        }
        if(T[i]=='*'){
            ans *= A[i];
        }
        if(ans<0) {
            ans +=  10000;
        }
        ans %= 10000;
        cout << ans <<'\n';
    }
}