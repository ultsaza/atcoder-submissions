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
    int q; cin >> q;
    queue<string> t;
    rep(i,q) {
        int type; cin >> type;
        string name;
        if(type==1) {
            string name; cin >> name;
            t.push(name);
        }
        if(type==2) {
            cout << t.front() << '\n';
        }
        if(type==3) {
            t.pop();
        }
    }
}