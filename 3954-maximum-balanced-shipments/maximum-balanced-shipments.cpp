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
    int maxBalancedShipments(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        ll rmx = -1;
        ll cnt = 0;
        f(i, 0, n) {
            if (cnt == 0)
                rmx = nums[i], cnt++;
            else {
                rmx = max((ll)nums[i], rmx);
                if (rmx != nums[i])
                    cnt = 0, ans++, rmx = -1;
                else
                    cnt++;
            }
        }
        return ans;
    }
};