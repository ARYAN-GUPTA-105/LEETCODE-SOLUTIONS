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
    int maxBalancedSubarray(vector<int>& nums) {
        ll n = nums.size();
        ll xr = 0, odd = 0, even = 0, ans = 0;
        map<pair<ll,ll>,ll> mp;
        mp[{0,0}] = -1;
        f(i,0,n){
            xr ^= nums[i];
            if(nums[i] % 2) odd++;
            else even++;
            pair<ll,ll> p = {xr,odd - even};
            if(mp.count(p)) ans = max(ans,i - mp[p]);
            else mp[p] = i;
        }
        return ans;
    }
};