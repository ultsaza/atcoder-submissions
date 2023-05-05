#include<iostream>
using namespace std;

int main() {
  int t,n;
  cin >> t >> n;
  int l[500009],r[500009];
  int rat[500009];
  for(int i=0;i<n;i++) {
    cin >> l[i] >> r[i];
    rat[l[i]]++;
    rat[r[i]]--;
  }
  int oput[500009];
  oput[0]=rat[0];
  for(int i=0;i<t;i++) {
    oput[i+1]=oput[i]+rat[i+1];
  }
  for(int i=0;i<t;i++) {
    cout << oput[i] << endl;
  }
}