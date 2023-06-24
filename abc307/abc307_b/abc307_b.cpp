#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i < (int)(n); i++)
const ll M=1000000007;

bool palindrome(const string& s){
    return equal(s.begin(), s.end(), s.rbegin());
}
int main(){
    int n;
    vector<string> s(109);
    cin >> n;
    rep(i,n) cin >> s[i];
    bool b=false;
    rep(i,n-1) {
        rep2(j,i+1,n) {
            if(palindrome(s[i]+s[j])) b=true;
            if(palindrome(s[j]+s[i])) b=true;
            //cout << s[i]+s[j] << " ";
        }
    }
    if(b) cout << "Yes";
    else cout << "No";
}