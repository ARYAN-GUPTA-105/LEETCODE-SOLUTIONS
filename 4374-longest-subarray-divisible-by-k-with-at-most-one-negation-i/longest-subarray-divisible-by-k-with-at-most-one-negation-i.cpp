#include <bits/stdc++.h>
using namespace std;
#define ll long long
using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvii = vector<vector<int>>;
#define f(i, a, n) for (ll i = a; i < n; i++)
#define rf(i, a, n) for (ll i = a; i >= n; i--)
#define pb push_back
#define um unordered_map
#define us unordered_set
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0;
        vll rem(k, 0);
        ll val = (1e9 / k) * k;
        f(i, 0, n) {
            ll sum = 0;
            f(j, i, n) {
                sum += nums[j];
                rem[((2 * nums[j]) + val) % k] = 1;
                if (((sum % k) == 0) || (rem[(sum + val) % k] != 0))
                    ans = max(ans, j - i + 1);
            }
            f(j, 0, k) rem[j] = 0;
        }
        return ans;
    }
};