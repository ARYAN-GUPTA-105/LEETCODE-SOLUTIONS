class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int mx = 0;
        int mn = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[mx])
                mx = i;
            if (nums[i] < nums[mn])
                mn = i;
        }
        int l = max(mx, mn) + 1;
        int r = max(n - mx, n - mn);
        int b = min(mn + 1 + n - mx, mx + 1 + n - mn);
        return min({l, r, b});
    }
};