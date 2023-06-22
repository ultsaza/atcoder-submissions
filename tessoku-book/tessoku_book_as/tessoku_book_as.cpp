#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i= (s); i < (int)(n); i++)
const ll M=1000000007;

int N;
char C;
string A;
int main(){
    cin >> N >> C >> A;
    int score=0;
    rep(i,N) {
        if(A[i]=='B') score++;
        if(A[i]=='R') score+=2;
    }
    int sub;
    if(C=='W') sub=0;
    if(C=='B') sub=1;
    if(C=='R') sub=2;
    if(score%3 == sub) cout << "Yes";
    else cout << "No";
}