#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  string op;
  cin >> A >> op >> B;

  if (op == "+") {
    cout << A + B << endl;
  }
  if (op == "-") {
    cout << A - B << endl;
  }
  if (op == "*") {
    cout << A * B << endl;
  }
  if (op == "/" && B == 0) {
    cout << "error" << endl;
  }
  if (op == "/" && B != 0) {
    cout << A / B << endl;
  }
  if (op == "?" || op == "=" || op == "!") {
    cout << "error" << endl;
  }
    
}
