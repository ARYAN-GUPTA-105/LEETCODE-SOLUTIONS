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
    vector<long long> resultArray(vector<int>& nums, int k) {
        vll ans(k, 0), dp(k, 0);
        ll n = nums.size();
        f(i, 0, n) {
            ll x = nums[i] % k;
            vll nxt(k, 0);
            nxt[x]++;
            f(j, 0, k) {
                ll a = (j * x) % k;
                nxt[a] += dp[j];
            }
            f(j, 0, k) ans[j] += nxt[j]; 
            dp = nxt;
        }
        return ans;
    }
};