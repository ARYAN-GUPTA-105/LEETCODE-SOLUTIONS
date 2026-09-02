class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while (i+1 < n && nums[i + 1] > nums[i])
            i++;
        long long sf = 0;
        long long sd = 0;
        for (int j = 0; j < i; j++) {
            sf += nums[j];
        }
        for (int j = i + 1; j < n; j++) {
            sd += nums[j];
        }
        if (sf > sd)
            return 0;
        else if (sf < sd)
            return 1;
        else
            return -1;
    }
};