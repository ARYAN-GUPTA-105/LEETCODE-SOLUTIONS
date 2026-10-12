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
    int resilientSubarray(vector<int>& nums, int k) {
        ll n = nums.size(), ans = 1, idx = 0;
        while (idx < n) {
            ll r = nums[idx] % k, j = idx;
            while (j < n && nums[j] % k == r)
                j++;
            ll diff = j - idx;
            ll x = k / gcd(r, k);
            ll m = ((diff - 1) / x) * x + 1;
            ans = max(ans, m);
            idx = j;
        }
        return ans;
    }
};