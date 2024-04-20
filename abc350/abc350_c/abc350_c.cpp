#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
const ll INF = 0x1ffffffffffffff;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N+1);
    //jの位置はB[j]になる
    vector<ll> B(N+1);
    vector<pair<int,int>> ans;
    ll K = 0;
    rep(i,1,N+1) {
        cin >> A[i];
    }

    
    rep(i,1,N+1) {
        B[A[i]] = i; 
    }

    rep(i,1,N) {
        if(B[i] != i) {
            K ++;
            ans.push_back({i,B[i]});
            swap(A[i],A[B[i]]);
            swap(B[i],B[A[B[i]]]);

        }
    }

    cout << K << endl;
    for(auto p : ans) {
        cout << p.first<< " " << p.second << endl;
    }
}