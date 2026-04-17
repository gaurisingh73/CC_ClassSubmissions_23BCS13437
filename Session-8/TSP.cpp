#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int tsp(vector<vector<int>>& cost) {
    int n = cost.size();
    if (n <= 1) return n == 1 ? cost[0][0] : 0;
    
    const int INF = INT_MAX;
    int FULL = 1 << n, fullMask = FULL - 1;
    
    vector<vector<int>> dp(FULL, vector<int>(n, INF));
    dp[1][0] = 0; 
    
    for (int mask = 1; mask < FULL; mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;
            if (dp[mask][i] == INF) continue;
            
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                
                int nxt = mask | (1 << j);
                dp[nxt][j] = min(dp[nxt][j], dp[mask][i] + cost[i][j]);
            }
        }
    }
    
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (dp[fullMask][i] != INF) 
            ans = min(ans, dp[fullMask][i] + cost[i][0]);
    }

    return ans;
}

int main() {
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int res = tsp(cost);
    cout << res;
}
