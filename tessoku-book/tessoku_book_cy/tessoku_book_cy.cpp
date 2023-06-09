#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int n; bool Deleted[1000009];
int main() {
    cin >> n;
    for(int i=1;i<=1000009;i++) {
        Deleted[i]=false; // false -> prime
    }
    for(int i=2;i*i<=n;i++) {
        if(Deleted[i]) {
            continue;
        }
        for(int j=i*2;j<=n;j+=i) {
            Deleted[j]=true;
        }
    }
    for(int i=2;i<=n;i++) {
        if(!Deleted[i]) {
            cout << i << '\n';
        }
    }
}