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
    ll mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        ll n = nums.size();
        sort(nums.begin(), nums.end());
        vll arr(32, 0);
        f(i, 0, n) {
            f(j, 0, 32) {
                if (nums[i] & (1 << j)) arr[j]++;
            }
        }
        ll ans = 0;
        while (k--) {
            ll curr = 0;
            f(i, 0, 31) {
                if (arr[i] > 0) {
                    curr |= (1ll << i);
                    arr[i]--;
                }
            }
            ans = (ans + curr * curr) % mod;
        }
        return ans;
    }
};