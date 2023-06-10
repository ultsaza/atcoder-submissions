#include<iostream>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
const ll M=1000000007;

int main() {
    int h,w;
    char s[509][509];
    cin >> h >> w;
    rep(i,h) {
        rep(j,w) {
            cin >> s[i][j];
        }
    }
    rep2(i,0,h+1) {
        s[i][0]='.';
    }
    rep2(j,0,w+1) {
        s[0][j]='.';
    }
    rep(i,h+1) {
        s[i][w+1];
    }
    rep(j,w+1) {
        s[h+1][j];
    }
    rep(i,h) {
        rep(j,w) {
            if(s[i][j]=='.') {
                if((s[i-1][j]=='#'||s[i+1][j]=='#') && (s[i][j-1]=='#'||s[i][j+1]=='#')) {
                    cout << i <<" "<< j;
                }
            }
        }
    }
}