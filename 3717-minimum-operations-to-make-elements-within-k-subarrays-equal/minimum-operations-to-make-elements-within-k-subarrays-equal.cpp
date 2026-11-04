//tantar mantar & just not capable of
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
    long long minOperations(vector<int>& nums, int x, int k) {
        ll n = nums.size();
        vi v(nums);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        ll m = v.size();
        vi r(n);
        f(i, 0, n) r[i] =
            lower_bound(v.begin(), v.end(), nums[i]) - v.begin() + 1;
        vi cnt(m + 1, 0);
        vll s(m + 1, 0);
        ll top = 1;
        while (top * 2 <= m)
            top *= 2;
        ll need = (x + 1) / 2, w = n - x + 1;
        vll cost(w);
        ll tot = 0;
        f(i, 0, n) {
            tot += nums[i];
            for (ll p = r[i]; p <= m; p += p & -p)
                cnt[p] += 1, s[p] += nums[i];
            if (i >= x) {
                tot -= nums[i - x];
                for (ll p = r[i - x]; p <= m; p += p & -p)
                    cnt[p] -= 1, s[p] -= nums[i - x];
            }
            if (i >= x - 1) {
                ll pos = 0, rem = need;
                ll s0 = 0;
                for (ll p = top; p > 0; p >>= 1) {
                    ll nxt = pos + p;
                    if (nxt <= m && cnt[nxt] < rem)
                        pos = nxt, rem -= cnt[nxt], s0 += s[nxt];
                }
                ll med = v[pos], c0 = need - rem;
                cost[i - x + 1] = med * c0 - s0 + (tot - s0) - med * (x - c0);
            }
        }
        vll prev(n + 1, 0), curr(n + 1, 0);
        ll inf = 1000000000000000000LL;
        f(j, 0, k) {
            f(i, 0, x) curr[i] = inf;
            f(i, x, n + 1) curr[i] = min(curr[i - 1], prev[i - x] + cost[i - x]);
            swap(prev, curr);
        }
        return prev[n];
    }
};