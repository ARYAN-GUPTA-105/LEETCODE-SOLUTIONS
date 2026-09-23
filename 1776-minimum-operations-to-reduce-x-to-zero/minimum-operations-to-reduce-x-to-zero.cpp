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
    int minOperations(vector<int>& nums, int x) {
        ll n = nums.size(), sum = 0;
        for (ll x : nums)
            sum += x;
        ll t = sum - x;
        if (t == 0)
            return n;
        if (t < 0)
            return -1;
        ll l = 0, w = 0, b = -1;
        f(r, 0, n) {
            w += nums[r];
            while (w > t)
                w -= nums[l++];
            if (w == t)
                b = max(b, r - l + 1);
        }
        return b == -1 ? -1 : n - b;
    }
};