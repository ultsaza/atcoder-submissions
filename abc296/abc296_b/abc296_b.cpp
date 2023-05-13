#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    int x,y;
    vector<string> s(8);
    for(int i=0;i<8;i++) {
        cin >> s[i];
    }
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if((s[i])[j]=='*'){
                x=j;
                y=8-i;
            }
        }
    }
    cout << (char)('a'+x)<<y;
}