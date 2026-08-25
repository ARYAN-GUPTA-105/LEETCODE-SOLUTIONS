#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvii = vector<vector<int>>;
#define f(i, a, n) for (int i = a; i < n; i++)
#define rf(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
class Solution {
public:
    bool helper(int i, int j, vector<string>& strs){
        f(k,0,strs.size()) if(strs[k][i] > strs[k][j]) return false;
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        vi dp(m);
        int ans = 0;
        f(i,0,m){
            dp[i] = 1;
            f(j,0,i) if(helper(j,i,strs)) dp[i] = max(dp[i],dp[j]+1);
            ans = max(ans,dp[i]);
        }
        return m - ans;
    }
};