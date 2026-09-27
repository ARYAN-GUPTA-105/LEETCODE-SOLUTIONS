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
    int maxEqualAdjacentPairs(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        map<pair<ll, ll>, ll> mp;
        f(i, 0, n - 1) {
            if (nums[i] == nums[i + 1]) {
                ans++;
            } else {
                ll x = min(nums[i], nums[i + 1]);
                ll y = max(nums[i], nums[i + 1]);
                mp[{x, y}]++;
            }
        }
        ll mx = 0;
        for (auto& [p, cnt] : mp)
            mx = max(mx, cnt);
        return ans + mx;
    }
};