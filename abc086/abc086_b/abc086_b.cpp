#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;


/*bool is_Prime(int x) {
    for(int i=2;i*i<=x;i++) {
        if(i%x ==0 ) return false;
    }
    return true;
}

vector<int> dv(1000000,0);
void factor_num(int x) {
    for(int i=2;i<=x;i++) if(is_Prime(i)){
        if(x%i == 0) {
            int p=1;

            while(x % (int)(pow(i,p) == 0)) {
                dv[i]++;
            }
        }
    }
    return;
}*/
int main() {
    string a,b; cin >> a >> b;
    string s = a + b;
    int n=atoi(s.c_str());
    
    for(int i=1;i*i<=100100;i++) {
        if(i*i==n) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}