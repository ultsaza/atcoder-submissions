#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    bool b=1;
    if(s[0]=='M') {
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                if(s[i]=='F') {
                    b=0;
                }
            } else {
                if(s[i]=='M') {
                    b=0;
                }
            }
        }
    } else {
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                if(s[i]=='M') {
                    b=0;
                }
            } else {
                if(s[i]=='F') {
                    b=0;
                }
            }
        }
    }
    if(b) {
        cout << "Yes";
    } else  {
        cout << "No";
    }
}