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
    int minOperations(vector<int>& nums) {
        ll n = nums.size(), cnt = 0;
        f(i, 0, n) if (nums[i] == 1) cnt++;
        if (cnt) return n - cnt;
        ll s = INT_MAX;
        f(i, 0, n) {
            f(j, i + 1, n) {
                nums[i] = gcd(nums[i], nums[j]);
                if (nums[i] == 1) s = min((int)s, (j - i + 1));
            }
        }
        return (s == INT_MAX) ? -1 : s + n - 2;
    }
};