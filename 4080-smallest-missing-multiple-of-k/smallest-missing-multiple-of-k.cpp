class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp;
        for(int x : nums) mp.insert(x);
        int i = 1;
        while(mp.find(k * i) != mp.end()) i++;
        return k * i;
    }
};