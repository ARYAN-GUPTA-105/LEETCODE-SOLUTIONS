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
    vector<int> maximumWeight(vector<vector<int>>& ivl) {
        ll n = ivl.size();
        vvll nums(n, vll(4));
        f(i, 0, n) nums[i] = {ivl[i][1], ivl[i][0], ivl[i][2], i};
        sort(nums.begin(), nums.end());
        vvll dp(n + 1, vll(5, 0));
        vector<vvii> idx(n + 1, vvii(5));
        f(i, 1, n + 1) {
            ll l = nums[i - 1][1];
            ll wgt = nums[i - 1][2];
            ll ogidx = nums[i - 1][3];
            ll p = 0;
            ll low = 0, hi = i - 2;
            while (low <= hi) {
                ll mid = low + (hi - low) / 2;
                if (nums[mid][0] < l)
                    p = mid + 1, low = mid + 1;
                else
                    hi = mid - 1;
            }
            f(j, 1, 5) {
                dp[i][j] = dp[i - 1][j];
                idx[i][j] = idx[i - 1][j];
                ll scr = dp[p][j - 1] + wgt;
                vi idx2 = idx[p][j - 1];
                idx2.pb(ogidx);
                sort(idx2.begin(), idx2.end());
                if ((scr == dp[i][j] && idx2 < idx[i][j]) || scr > dp[i][j])
                    dp[i][j] = scr, idx[i][j] = idx2;
            }
        }
        vi ans = idx[n][4];
        return ans;
    }
};