class Solution {
public:
    int mx = 100005;
    vector<int> spf;
    void helper() {
        spf.resize(mx);
        for (int i = 0; i < mx; i++)
            spf[i] = i;
        for (int i = 2; i * i < mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < mx; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }
    vector<int> fact(int x) {
        vector<int> res;
        while (x > 1) {
            int p = spf[x];
            res.push_back(p);

            while (x % p == 0)
                x /= p;
        }
        return res;
    }
    int longestSubarray(vector<int>& nums, int k) {
        helper();
        unordered_map<int, int> cnt;
        int l = 0;
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            for (int p : fact(nums[j]))
                cnt[p]++;
            while (cnt.size() > k) {
                for (int p : fact(nums[l])) {
                    cnt[p]--;
                    if (cnt[p] == 0)
                        cnt.erase(p);
                }
                l++;
            }
            ans = max(ans, j - l + 1);
        }
        return ans;
    }
};