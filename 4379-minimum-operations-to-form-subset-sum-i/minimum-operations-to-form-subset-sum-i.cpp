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
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vll dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for (ll x : nums) {
            vector<pair<ll, ll>> vec;
            for (ll v = x, k = 0; v <= sum; v *= 2, k++)
                vec.pb({v, k});
            for (ll v = x, d = 1; v > 0; d++) {
                v /= 2;
                if (v > 0 && v <= sum)
                    vec.pb({v, d});
            }
            vll ndp(dp);
            for (auto& [v, c] : vec)
                rf(s, sum, v) if (dp[s - v] != INT_MAX) ndp[s] = min(ndp[s], dp[s - v] + c);
            dp = ndp;
        }
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};