#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    string x,y;
    cin >> n >> x >> y;
    bool b=1;
    for(int i=0;i<n;i++) {
        if(x[i]==y[i] || (x[i]== '1' && y[i]== 'l') || (x[i]=='l' && y[i]=='1') ||
        (x[i]=='0' && y[i]=='o') || (x[i]== 'o' && y[i]=='0')) {
            
        } else {
            b=0;
        }
    }
    if(b==1) {
        cout << "Yes";
    }else {
        cout << "No";
    }
}