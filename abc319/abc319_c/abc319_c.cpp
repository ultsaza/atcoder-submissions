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


int main() {
   vector<int> cells(9);
   rep(i,9) cin >> cells[i];
   vector<tuple<int, int, int>>  row{{0, 1, 2}, // 上から 1 行目
                                     {3, 4, 5}, // 上から 2 行目
                                     {6, 7, 8}, // 上から 3 行目
                                     {0, 3, 6}, // 左から 1 列目
                                     {1, 4, 7}, // 左から 2 列目
                                     {2, 5, 8}, // 左から 3 列目
                                     {0, 4, 8}, // 左上から右下
                                     {2, 4, 6}};// 右上から左下
    vector<int> order(9);
    iota(all(order),0);//do-while するための初期化
    int no_dis =0,all=0;
    do{
        all++;
        bool disappoint_flag = false;
        for(auto &&[a,b,c]:row) {
             if (cells[a] == cells[b] && order[a] < order[c] && order[b] < order[c])
                disappoint_flag = true;
            // 同じ数字のペアが残り 2 通りの場合も同様
            else if (cells[a] == cells[c] && order[a] < order[b] && order[c] < order[b])
                disappoint_flag = true;
            else if (cells[b] == cells[c] && order[b] < order[a] && order[c] < order[a])
                disappoint_flag = true;
        }
        if(!disappoint_flag) {
            no_dis++;
        } 
    } while (next_permutation(all(order)));
    cout << setprecision(10); ///桁数指定できるらしい
    cout << (double)no_dis/all<< endl;
}