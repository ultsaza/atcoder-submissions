#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int GCD(int a,int b) {
    while(a>0 && b>0) {
        if(a>=b) {
            a=(a%b);
        } else {
            b=(b%a);
        }
    }
    if(a != 0) {
        return a;
    } else {
        return b;
    }
}
int main () {
    int a,b;
    cin >> a >> b;
    cout << GCD(a,b) << '\n';
}