class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans = 0;
        int last = INT_MIN;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int curr = max(nums[i] - k, last + 1);
            if (curr <= nums[i] + k)
                last = curr, ans++;
        }
        return ans;
    }
};