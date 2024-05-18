#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int N;
vector<int> A, B;
unordered_map<int, bool> memo;

bool canWin(int mask) {
    if (memo.find(mask) != memo.end()) {
        return memo[mask];
    }
    
    for (int i = 0; i < N; ++i) {
        if (mask & (1 << i)) {
            for (int j = i + 1; j < N; ++j) {
                if (mask & (1 << j)) {
                    if (A[i] == A[j] || B[i] == B[j]) {
                        int new_mask = mask & ~(1 << i) & ~(1 << j);
                        if (!canWin(new_mask)) {
                            return memo[mask] = true;
                        }
                    }
                }
            }
        }
    }
    
    return memo[mask] = false;
}

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    
    int initial_mask = (1 << N) - 1;
    if (canWin(initial_mask)) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
    
    return 0;
}
