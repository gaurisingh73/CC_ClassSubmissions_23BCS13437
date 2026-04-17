class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            int maxVal = 0;

            for (int len = 1; len <= k && i - len + 1 >= 0; len++) {
                maxVal = max(maxVal, arr[i - len + 1]);

                int prev = (i - len >= 0) ? dp[i - len] : 0;

                dp[i] = max(dp[i], prev + maxVal * len);
            }
        }

        return dp[n - 1];
    }
};
