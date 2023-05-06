#include<iostream>
#include<algorithm>
using namespace std;

int n,a[100009];
int q,x[100009];

int search(int y) {
    int pos = lower_bound(a+1,a+n+1,y) - a;
    if(pos == n+1) {
        return n;
    }
    else {
        return pos-1;
    }
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 1; i <=q; i++)
    {
        cin >> x[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <=q; i++)
    {
        cout <<  search(x[i]);
        cout << endl;
    }
}

