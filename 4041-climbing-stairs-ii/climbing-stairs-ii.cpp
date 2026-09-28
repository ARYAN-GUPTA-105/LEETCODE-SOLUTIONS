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
class Solution {
public:
    ll helper(vi& costs, int i, vll& dp) {
        if (i == 0)
            return 0;
        if (i < 0)
            return INT_MAX;
        if (dp[i] != -1)
            return dp[i];
        ll cost = INT_MAX;
        f(j, 1, 4) {
            ll prev = i - j;
            ll anscost = INT_MAX;
            if (prev >= 0) {
                anscost = costs[i - 1] + helper(costs, prev, dp) +
                          (i - prev) * (i - prev);
            }
            cost = min(anscost, cost);
        }
        return dp[i] = cost;
    }
    int climbStairs(int n, vector<int>& costs) {
        vll dp(n + 1, -1);
        return helper(costs, n, dp);
    }
};