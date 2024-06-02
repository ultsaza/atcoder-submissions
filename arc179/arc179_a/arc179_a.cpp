#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,0,N) cin >> A[i];
    vector<ll> B(N);
    rep(i,0,N) B[i] = A[i];
    sort(all(A));
    sort(all(B));
    reverse(all(B));

    vector<ll> acm(N+1), acm2(N+1);
    acm[0] = 0;
    ll min_acm = 0;
    ll max_acm = 0;
    ll min_acm_2 = 0;
    ll max_acm_2 = 0;

    rep(i,0,N) {
        acm[i+1] = acm[i] + A[i];
        min_acm = min(min_acm, acm[i+1]);
        max_acm = max(max_acm, acm[i+1]);

        acm2[i+1] = acm2[i] + B[i];
        min_acm_2 = min(min_acm_2, acm2[i+1]);
        max_acm_2 = max(max_acm_2, acm2[i+1]);
    }
    
    if(A[0] >= 0) {//acmが単調増加
        cout << "Yes" << endl;
        rep(i,0,N) cout << A[i] << " ";
        cout << endl;
        return 0;
    } else {
        if(acm[N] < 0 && (K>0 || K<=min_acm)) {
            cout << "Yes" << endl;
            rep(i,0,N) cout << A[i] << " ";
            cout << endl;
            return 0;
        }
        if(acm[N]>0 && (K<=min_acm || K > 0 ) ) {
            cout << "Yes" << endl;
            rep(i,0,N) cout << A[i] << " ";
            cout << endl;
            return 0;
        }
        if(acm[N] == 0 && (K>0 || K<=min_acm)) {
            cout << "Yes" << endl;
            rep(i,0,N) cout << A[i] << " ";
            cout << endl;
            return 0;
        }
        if(acm2[N]>0 && (K<=acm2[N] || K>max_acm_2)) {
            cout << "Yes" << endl;
            rep(i,0,N) cout << B[i] << " ";
            cout << endl;
            return 0;
        }
        if(acm2[N]<0 && (K>max_acm_2 || K<=acm2[N])) {
            cout << "Yes" << endl;
            rep(i,0,N) cout << B[i] << " ";
            cout << endl;
            return 0;
        }
        if(acm2[N] == 0 && (K>max_acm_2 || K<=acm2[N])) {
            cout << "Yes" << endl;
            rep(i,0,N) cout << B[i] << " ";
            cout << endl;
            return 0;
        }
    }

    

    cout << "No" << endl;
    


}