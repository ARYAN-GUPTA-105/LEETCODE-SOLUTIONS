class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] == nums[i - 1]) {
                cnt++;
                if (cnt <= k)
                    ans.push_back(nums[i]);
            } else {
                cnt = 1;
                if (cnt <= k)
                    ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};