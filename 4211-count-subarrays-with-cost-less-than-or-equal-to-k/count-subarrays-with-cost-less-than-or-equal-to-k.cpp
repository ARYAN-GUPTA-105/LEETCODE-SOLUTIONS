#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define endl '\n'

using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvii = vector<vector<int>>;
#define f(i, a, n) for (int i = a; i < n; i++)
#define rf(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int st = 0;
        ll ans = 0;
        map<ll,ll> mp;
        f(end,0,n){
            mp[nums[end]]++;
            while(st <= end){
                ll h = mp.rbegin()->first;
                ll l = mp.begin()->first;
                ll cost = (h - l) * (end - st + 1);
                if(cost <= k) break;
                mp[nums[st]]--;
                if(mp[nums[st]] == 0) mp.erase(nums[st]);
                st++;
            }
            ans += end - st + 1;
        }
        return ans;
    }
};