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
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vi close(n);
        f(i, 0, n) {
            if (i == 0)
                close[i] = 1;
            else if (i == n - 1)
                close[i] = n - 2;
            else {
                int left = nums[i] - nums[i - 1];
                int right = nums[i + 1] - nums[i];
                if (left <= right)
                    close[i] = i - 1;
                else
                    close[i] = i + 1;
            }
        }
        vll prefRight(n, 0);
        vll prefLeft(n, 0);
        f(i, 0, n - 1) {
            if (close[i] == i + 1)
                prefRight[i + 1] = prefRight[i] + 1;
            else
                prefRight[i + 1] = prefRight[i] + (nums[i + 1] - nums[i]);
        }
        f(i, 1, n) {
            if (close[i] == i - 1)
                prefLeft[i] = prefLeft[i - 1] + 1;
            else
                prefLeft[i] = prefLeft[i - 1] + (nums[i] - nums[i - 1]);
        }
        vi ans;
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            if (l < r)
                ans.pb(prefRight[r] - prefRight[l]);
            else
                ans.pb(prefLeft[l] - prefLeft[r]);
        }
        return ans;
    }
};