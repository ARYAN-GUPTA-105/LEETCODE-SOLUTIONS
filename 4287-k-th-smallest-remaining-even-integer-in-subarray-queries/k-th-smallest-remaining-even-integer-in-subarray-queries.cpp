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
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums,
                                    vector<vector<int>>& queries) {
        vi ans;
        int n = nums.size();
        vi pre(n + 1);
        f(i, 1, n + 1) pre[i] += pre[i - 1] + ((nums[i - 1] % 2 == 0) ? 1 : 0);
        for (auto& x : queries) {
            int low = x[0], high = x[1], k = x[2];
            int l = (nums[low] - 1) / 2, u = nums[high] / 2,
                r = pre[high + 1] - pre[low];
            if (u - r < k) {
                ans.pb(2 * (k + r));
                continue;
            }
            if (l >= k) {
                ans.pb(2 * k);
                continue;
            }
            int i = low, j = high;
            while (i <= j) {
                int mid = i + (j - i) / 2;
                int val = nums[mid] / 2, rem = pre[mid + 1] - pre[low];
                if (val - rem < k)
                    i = mid + 1;
                else
                    j = mid - 1;
            }
            ans.pb(2 * (k + pre[i] - pre[low]));
        }
        return ans;
    }
};