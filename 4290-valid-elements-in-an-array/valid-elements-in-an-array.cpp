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
    vector<int> findValidElements(vector<int>& nums) {
        ll n = nums.size();
        if (n == 1 || n == 2)
            return nums;
        vi right(n);
        right[n - 1] = nums[n - 1];
        rf(i, n - 2, 0) right[i] = max(right[i + 1], nums[i]);
        vi ans;
        int l = -1;
        f(i, 0, n) {
            if (nums[i] > l || (i == n - 1 || nums[i] > right[i + 1])) {
                ans.pb(nums[i]);
            }
            l = max(l, nums[i]);
        }
        return ans;
    }
};