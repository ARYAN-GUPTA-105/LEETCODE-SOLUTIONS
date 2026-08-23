class Solution {
public:
    int helper(vector<int>&s,vector<vector<int>>& dp,int sum,int i){
        if(!sum) return 0;
        if(!i){
            if(!(sum % s[i])) return sum/s[i];
            return 1e5;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int n = helper(s,dp,sum,i-1);
        int t = INT_MAX;
        if(s[i] <= sum) t = helper(s,dp,sum-s[i],i) + 1;
        return dp[i][sum] = min(t,n);
    }
    int numSquares(int n) {
        vector<int> s;
        int i = 1;
        while(true){
            if(i*i <= n) s.push_back(i*i), i++;
            else break;
        }
        int sz = s.size();
        vector<vector<int>> dp(sz,vector<int>(n+1,-1));
        return helper(s,dp,n,sz-1);
    }
};