#include <bits/stdc++.h>
using namespace std;
#define ll long long
using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvii = vector<vector<int>>;
#define f(i, a, n) for (int i = a; i < n; i++)
#define rf(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
#define um unordered_map
#define us unordered_set
#define pob pop_back
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        ll n = nums.size(), ans = 0;
        sort(nums.begin(),nums.end());
        vll dp(nums[n-1] + 5);
        for(ll x : nums) dp[x+1] = dp[x] + 1, dp[x] = dp[x - 1] + 1, ans = max({ans,dp[x],dp[x+1]});
        return ans;
    }
};