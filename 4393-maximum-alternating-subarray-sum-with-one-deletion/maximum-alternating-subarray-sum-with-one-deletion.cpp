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
    ll mod = -1e9;
    long long maxAlternatingSum(vector<int>& nums) {
        ll x = mod, y = mod, z = mod, m = mod, ans = mod, n = nums.size();
        f(i, 0, n) {
            ll curr = max(x, m + (ll)nums[i]);
            m = max(y, z - (ll)nums[i]);
            z = curr;
            curr = max(y + (ll)nums[i], (ll)nums[i]);
            y = x - (ll)nums[i];
            x = curr;
            ans = max({ans, x, y, m, z});
        }
        return ans;
    }
};