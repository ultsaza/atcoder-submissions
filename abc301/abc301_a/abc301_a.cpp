#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int t=0,a=0;
    for (int  i = 0; i < n; i++)
    {
        if(s[i]=='T') {
            t++;
        } else {
            a++;
        }
    }
    if(a>t) {
        cout << 'A';
    }
    if (a<t)
    {
        cout << 'T';
    }
    if(a==t) {
       for (int  i = 0; i < n-1; i++) {
        if(s[i]=='T') {
            t++;
        } else {
            a++;
        }
    }
    if (a>t)
    {
        cout << 'A';
    } else {
        cout << 'T';
    }
    
    }
    
}