class Solution {
public:
    int solve(vector<int>& coins, vector<int>& vec, int r) {
        if (r < 0)
            return -1;
        if (!r)
            return 0;
        if (vec[r] != -2)
            return vec[r];
        int mn = INT_MAX;
        for (int c : coins) {
            int ans = solve(coins, vec, r - c);
            if (ans >= 0 && ans < mn)
                mn = 1 + ans;
        }
        vec[r] = (mn == INT_MAX) ? -1 : mn;
        return vec[r];
    }
    int coinChange(vector<int>& coins, int a) {
        vector<int> vec(a+1,-2);
        return solve(coins,vec,a);
    }
};