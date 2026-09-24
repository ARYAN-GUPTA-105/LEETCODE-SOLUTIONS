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
    long long maxSumTrionic(vector<int>& nums) {
        ll LONG_MINN = -1e17;
        ll ans = LONG_MINN, a = LONG_MINN, b = LONG_MINN, c = LONG_MINN;
        ll pt = nums[0];
        ll n = nums.size();
        f(i, 0, n) {
            ll curr = nums[i];
            ll x = LONG_MINN, y = LONG_MINN, z = LONG_MINN;
            if (curr > pt) {
                x = max(a, pt) + curr;
                z = max(b, c) + curr;
            } else if (curr < pt)
                y = max(a, b) + curr;
            a = x, b = y, c = z;
            ans = max(ans, c);
            pt = curr;
        }
        return ans;
    }
};