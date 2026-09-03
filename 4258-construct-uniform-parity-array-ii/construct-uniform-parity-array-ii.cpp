class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0], oddfreq = 0;
        for(int x : nums1){
            oddfreq += (x % 2 == 0)? 0 : 1;
            mn = min(mn,x);
        }
        return (mn % 2) || !oddfreq;
    }
};