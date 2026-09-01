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
    int maxSubarraySumCircular(vector<int>& nums) {
        ll tot = 0, mns = nums[0], cmx = 0, cmn = 0, mxs = nums[0];
        for (ll x : nums) {
            cmx = max(cmx + x, x);
            mxs = max(mxs, cmx);
            cmn = min(cmn + x, x);
            mns = min(mns, cmn);
            tot += x;
        }
        if (mxs > 0)
            return max(mxs, tot - mns);
        return mxs;
    }
};