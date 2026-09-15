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
    int maximumSum(vector<int>& nums) {
        vll r0, r1, r2;
        ll n = nums.size();
        f(i, 0, n) {
            if (nums[i] % 3 == 0)
                r0.pb(nums[i]);
            else if (nums[i] % 3 == 1)
                r1.pb(nums[i]);
            else if (nums[i] % 3 == 2)
                r2.pb(nums[i]);
        }
        sort(r0.rbegin(), r0.rend());
        sort(r1.rbegin(), r1.rend());
        sort(r2.rbegin(), r2.rend());
        ll ans = 0;
        if (r0.size() >= 3) {
            ans = max(ans, r0[0] + r0[1] + r0[2]);
        }
        if (r1.size() >= 3) {
            ans = max(ans, r1[0] + r1[1] + r1[2]);
        }
        if (r2.size() >= 3) {
            ans = max(ans, r2[0] + r2[1] + r2[2]);
        }
        if (!r0.empty() && !r1.empty() && !r2.empty()) {
            ans = max(ans, r0[0] + r1[0] + r2[0]);
        }
        return ans;
    }
};