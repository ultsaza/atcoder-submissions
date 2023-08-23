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
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;

void kyomu() {
    int n,m,x,y;
    /*
    C1からC2に行く方法は8通り、各通りに対してC3,C4,C5の位置は一意に定まる
    ベクトルの定数倍の考え方を使ってみる
    まず方向ベクトル(dx,dy)を表す
    探索の方法は次の通り
    <1>C1の位置を決める
    <2>方向ベクトルを決める
    <3>定数倍の考えで他のCも表現する
    <4>グリットの範囲外に出たら探索をやめる
    <5>位置を探索時の方法で提示
    */
    vector<int> dx = {-1,-1,-1,0,0,1,1,1};
    vector<int> dy = {-1,0,1,-1,1,-1,0,1};
    string str;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    rep(i,n)rep(j,m)rep(k,8) {
        str="";
        rep(t,5) {
            x = i + t*dx[k];
            y = j + t*dy[k];
            if(x<0 || x>=n || y<0 || y>=m) break;
            str += s[x][y];
        }
        if(str=="snuke") {
            rep(t,5) {
                x = i + t*dx[k]+1;
                y = j + t*dy[k]+1;
                cout << x << " " << y << endl;
            }
        }
    }
    return;
}
int main() {
    kyomu();
    return 0;
}




