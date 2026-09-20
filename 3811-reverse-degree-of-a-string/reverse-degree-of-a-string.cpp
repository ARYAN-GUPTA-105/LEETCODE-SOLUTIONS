class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 1; i <= s.length(); i++) {
            int curr = 'z' - s[i-1] + 1;
            ans += curr * i;
        }
        return ans;
    }
};