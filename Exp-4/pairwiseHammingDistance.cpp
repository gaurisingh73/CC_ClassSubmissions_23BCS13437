#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int solve(vector<int> &A) {
    long long ans = 0;
    int n = A.size();

    // Check each bit position (0 to 31)
    for (int bit = 0; bit < 32; bit++) {
        long long count1 = 0;

        // Count numbers having this bit set
        for (int i = 0; i < n; i++) {
            if (A[i] & (1 << bit)) {
                count1++;
            }
        }

        long long count0 = n - count1;

        // Add contribution of this bit
        ans = (ans + (2LL * count1 % MOD * count0 % MOD) % MOD) % MOD;
    }

    return ans;
}

int main() {
    vector<int> A = {1, 3, 5};
    cout << solve(A) << endl;  // Output: 8
}
