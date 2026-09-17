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
    int minSumOfLengths(vector<int>& arr, int target) {
        ll n = arr.size(), ans = n + 1, sum = 0, idx = 0;
        vll dp(n + 1, n);
        f(i, 0, n) {
            sum += arr[i];
            while (sum > target)
                sum -= arr[idx++];
            dp[i + 1] = dp[i];
            if (sum == target) {
                ans = min(ans, i - idx + 1 + dp[idx]);
                dp[i + 1] = min(dp[i], i - idx + 1);
            }
        }
        return ans == n + 1 ? -1 : ans;
    }
};