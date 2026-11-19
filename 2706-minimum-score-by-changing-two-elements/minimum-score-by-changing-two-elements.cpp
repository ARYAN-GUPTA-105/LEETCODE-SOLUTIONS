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
#define pob pop_back
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        ll n = nums.size(), ans = 0;
        sort(nums.begin(),nums.end());
        ans = min({nums[n-1] - nums[2], nums[n-3] - nums[0], nums[n-2] - nums[1]});
        return ans;
    }
};