class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int l = lower;
        for (int x : nums) {
            if(x < l) continue;
            if(x > upper) break;
            vector<int> curr;
            if (x > l)
                curr.push_back(l), curr.push_back(x - 1);
            if (curr.size() != 0)
                ans.push_back(curr);
            l = x + 1;
            if(l > upper) break;
        }

        if (l <= upper) {
            vector<int> curr;
            curr.push_back(l);
            curr.push_back(upper);
            ans.push_back(curr);
        }
        return ans;
    }
};