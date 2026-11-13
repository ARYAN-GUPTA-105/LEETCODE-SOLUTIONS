//not completely
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
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        ll n = nums.size(), ans = 0, h = n, t = n, r = n - 1, w = 0;
        vll s(n);
        rf(i,n-1,0){
            while(h < t && nums[s[h]] <= nums[i]){
                ll j = s[h++];
                ll e = h < t ? s[h] : r + 1;
                w += (nums[i] - nums[j]) * (e - j);
            }
            s[--h] = i;
            while(w > k){
                w -= nums[s[t - 1]] - nums[r];
                if(s[t - 1] == r) t--;
                r--;
            }
            ans += r - i + 1;
        }
        return ans;
    }
};