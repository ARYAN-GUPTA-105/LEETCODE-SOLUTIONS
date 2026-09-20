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
    long long maxValue(vector<int>& nums) {
        ll n = nums.size(), ans = 0, mx = 0, mx2 = 0, mx3 = -1e9 - 7;
        f(i, 0, n) {
            if (i % 2) {
                ans -= nums[i];
                mx = max(mx, mx2 - ans);
                mx2 = max(mx2, ans);
            } else {
                ans += nums[i];
                mx = max(mx, mx3 - ans);
                mx3 = max(mx3, ans);
            }
        }
        return ans + 2 * mx;
    }
};