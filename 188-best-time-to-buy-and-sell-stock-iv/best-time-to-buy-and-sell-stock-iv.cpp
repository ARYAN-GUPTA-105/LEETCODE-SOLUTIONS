class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (!n || !k)
            return 0;
        if (k >= n / 2) {
            int ans = 0;
            for (int i = 1; i < n; i++) {
                ans += max(0, prices[i] - prices[i - 1]);
            }
            return ans;
        }
        vector<int> dp(n, 0);
        vector<int> dp2(n, 0);
        for (int j = 1; j < k + 1; j++) {
            int best = -prices[0];
            for (int i = 1; i < n; i++) {
                dp2[i] = max(dp2[i - 1], prices[i] + best);
                best = max(best, dp[i] - prices[i]);
            }
            dp = dp2;
        }
        return dp[n - 1];
    }
};