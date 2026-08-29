class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MIN;
        int dist = INT_MAX;
        for(int x : nums){
            if(abs(x) < dist) dist = abs(x), ans = x;
            if(abs(x) == dist) dist = abs(x), ans = max(x,ans);
        }
        return ans;
    }
};