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
    int n,x; cin >> n >> x;
    string a; cin >> a;
    queue<int> q;
    q.push(x);
    a[x-1]='@';
    while(!q.empty()) {
        int pos=q.front();
        q.pop();
        if(a[pos-1-1]=='.') {
            a[pos-1-1]='@';
            q.push(pos-1);
        }
        if(a[pos+1-1]=='.') {
            a[pos+1-1]='@';
            q.push(pos+1);
        }
    }
    cout << a;
}