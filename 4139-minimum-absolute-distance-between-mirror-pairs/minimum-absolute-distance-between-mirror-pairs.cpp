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
    int minMirrorPairDistance(vector<int>& nums) {
        um<ll,ll> mp;
        ll n = nums.size();
        ll ans = INT_MAX;
        f(i,0,n){
            if(mp.find(nums[i]) != mp.end()) ans = min(ans,abs(mp[nums[i]] - i));
            ll rev = 0;
            ll curr = nums[i];
            while(curr > 0){
                rev = rev * 10 + curr % 10;
                curr /= 10;
            }
            mp[rev] = i;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};