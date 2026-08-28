class Solution {
public:
    vector<string> res;
    void helper(int n, int k, string ans) {
        if (ans.length() == n) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (ans[i] == '1')
                    sum += i;
            }
            if (sum <= k)
                res.push_back(ans);
            return;
        }
        if(ans.back() == '1'){
            helper(n,k,ans + '0');
        }
        else{
            helper(n,k,ans + '1');
            helper(n,k,ans + '0');
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string ans;
        helper(n,k,ans + '0');
        helper(n,k,ans + '1');
        return res;
    }
};