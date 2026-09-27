//tantra mantra
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
    int maxSubarray(vector<int>& nums) {
        ll n = nums.size(), ans = 0, l = 0, w = 0;
        vi fs(1005, 0), ps(1005, 0);
        f(r, 0, n) {
            ll v = nums[r];
            w += ps[v];
            f(i, l, r) {
                ll s = nums[i] + v;
                w += fs[s];
                ps[s]++;
            }
            fs[v]++;
            while (w > 0 && l <= r) {
                ll x = nums[l];
                fs[x]--;
                f(i, l + 1, r + 1) {
                    ll s = x + nums[i];
                    ps[s]--;
                    w -= fs[s];
                }
                w -= ps[x];
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};