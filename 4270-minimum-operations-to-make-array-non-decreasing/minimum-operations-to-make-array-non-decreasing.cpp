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
    long long minOperations(vector<int>& nums) {
        ll ans = 0;
        ll mx = nums[0];
        ll n = nums.size();
        f(i, 1, n) {
            if (nums[i] + ans < mx) {
                ans += mx - (nums[i] + ans);
                nums[i] = mx;
                mx = max(mx, (ll)nums[i]);
            } else
                mx = max(mx, (ll)nums[i] + ans);
        }
        return ans;
    }
};